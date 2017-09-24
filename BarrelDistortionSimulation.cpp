#include "opencv2/opencv.hpp"

/*
 * Objective: Generate a distortion map to CAUSE distortion, rather than
 * to fix distortion.  Many web cams come with distortion corrections built in
 * and deliver an already corrected image, making study of corrections
 * difficult.  Images from a webcam can be run through the distortion maps
 * generated here immediately after capture and later corrected.  The map
 * can also include a shift of the center to test cx and cy corrections
 * in a camera matrix.
 */


// Generate a CV_32FC2 map the size of the image to cause barrel distortion
// using the model ru = rd (1 + k rd^2 ), where ru and rd are the undistorted
// and distorted radii, respectively.  Since this is a cubic equation, search
// for the solution.  Note that the distorted radius is less than the
// undistorted radius, hence the barrel shape.

// TODO: Implement cxDelta and cyDelta.
cv::Mat computeBarrelDistortionMap(cv::Size imageSize, float k = 0.0000002, double cxDelta = 0.0, double cyDelta = 0.0)
{
    const int ruOversample = 4;
    const int rdOversample = 10000;
    
    // Generate enough values to reach the farthest radius.
    int ruMax = pow(imageSize.width*imageSize.width*0.25 + imageSize.height*imageSize.height*0.25, 0.5);
    
    // Index = ru, output = rd, i.e. rd = f(ru).
    cv::Mat barrelRadialDistort = cv::Mat::zeros(ruMax*ruOversample, 1, CV_32F);
    
    // For every undistorted radius, need to find the distorted radius
    // which will be less than the undistorted radius.
    for (int ruX4 = 1, rdXStart = 1; ruX4 < ruMax*ruOversample; ruX4++)
    {
        std::cout << ruX4 << " " << (ruX4 / 4.0);
        
        float ru = ruX4 / (float) ruOversample;
        
        // Keep trying increasing distorted diameters.
        for (int rdX = rdXStart; rdX < ruMax*rdOversample; rdX++)
        {
            float rd = rdX / (float) rdOversample;
            
            float ruTest = rd * (1.0 + k * rd*rd);
            
            if (ruTest > ru)
                break;
            
            barrelRadialDistort.at<float>(ruX4,0) = rd;
            
            // A hueristic.  Don't start search from 0 each time since we know
            // that the curves are monotonic.
            rdXStart++;
        }
        
        std::cout << " " << barrelRadialDistort.at<float>(ruX4,0) << std::endl;
    }
    
    // Now that we know how to map each undistorted radius to a distorted radius,
    // generate a distortion map that can be used to quickly distort an image.
    cv::Mat map(imageSize, CV_32FC2);
    
    std::cout << "map.size() " << map.size() << std::endl;
    
    //    int c = 0, r = 0;
    
    for (int r=0; r<imageSize.height; r++)
        for (int c=0; c<imageSize.width; c++)
        {
            // Compute the coordinates of each pixel relative to the center.
            float x = c - (imageSize.width/2) + 0.5f;
            float y = r - (imageSize.height/2) + 0.5f;
            
            // Compute the radius.
            float rad = pow((float) (x*x + y*y), 0.5f);
            
            // Scale the radius, where scale >= 1 since the map determines "for the
            // present pixel position, from where should the actual pixel be retrieved?"
            // instead of "for the present pixel position, where should it be moved to?".
            float scale = rad / barrelRadialDistort.at<float>((int) rad * ruOversample, 0);
            x *= scale;
            y *= scale;
            
            map.at<cv::Vec2f>(r,c)[0] = x + (imageSize.width/2) - 0.5f;
            map.at<cv::Vec2f>(r,c)[1] = y + (imageSize.height/2) - 0.5f;
            
            // This causes the image to be squished to the top half of the frame,
            // leaving the bottom half all black and thereby revealing the meaning
            // of the entries of the map: "for the present pixel position, from
            // where should the actual pixel be retrieved?"
            // map.at<cv::Vec2f>(r,c)[0] = c;
            // map.at<cv::Vec2f>(r,c)[1] = r*2;
        }
    
    std::cout << map(cv::Rect(0,0,5,5));
    return map;
}


int main(int argc, const char * argv[]) {
    
    cv::Mat frame, frameDistorted;
    
    // Setup to capture live video frames.
    cv::VideoCapture cap(0);
    
    if (!cap.isOpened())
    {
        std::cout << "VideoCapture not able to open.";
        exit(1);
    }
    
    std::cout << "WIDTH " << cap.get(CV_CAP_PROP_FRAME_WIDTH) << "\n";
    std::cout << "HEIGHT " << cap.get(CV_CAP_PROP_FRAME_HEIGHT) << "\n";
    
    cv::Size imageSize = cv::Size(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    
    cv::Mat map = computeBarrelDistortionMap(imageSize);
    
    do {
        cap.read(frame);
        
        //        frame = cv::Mat::zeros(frame.size(), CV_8U);
        
        for (int r=40; r<frame.rows; r+=40)
            line(frame, cv::Point(0,r), cv::Point(frame.cols,r), cv::Scalar(0,0,255), 1);
        for (int c=40; c<frame.cols; c+=40)
            line(frame, cv::Point(c,0), cv::Point(c,frame.rows), cv::Scalar(0,0,255), 1);
        
        //            for (int c=0; c<frame.cols; c+=80)
        
        // 1280: 640 320 160 80
        //  720: 360 180  90 45
        
        cv::remap(frame, frameDistorted, map, cv::noArray(), CV_INTER_LINEAR);
        
        cv::imshow("Camera", frameDistorted);
    } while (cv::waitKey(1) != 27);
}
