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


// TODO: Implement cxDelta and cyDelta.
cv::Mat computeBarrelDistortionMap(cv::Size imageSize, float k = 0.0000002, double cxDelta = 0.0, double cyDelta = 0.0)
{
    // Find the center of the image assuming no cx or cy deviation, i.e. find the radius.
    cv::Point2f center(((double) imageSize.width-1.0)/2.0, ((double) imageSize.height-1.0)/2.0);
    
    std::cout << center;
    
    // The map, CV_32FC2, indicates for each point of the mapped image from where
    // in the original image to retrieve the pixel.  The formula for barrel distortion
    // as a function of the parameter k is: ru = rd (1 + k rd^2).  Note that rd <= ru.
    // Here, the points of the map are the distorted points and we use the formula to
    // find the position to take them from the undistorted image.
    cv::Mat map(imageSize, CV_32FC2);
    
    for (int y=0; y<imageSize.height; y++)
        for (int x=0; x<imageSize.width; x++)
        {
            cv::Point2f ptd(x-center.x, y-center.y);
            
            // Find the radius of the point in the distorted image, rd.
            float rd = cv::norm(ptd);
            
            // Determine the radius of the point in the undistorted image.
            float ru = rd * (1 + k*rd*rd);
            
            if (ptd.y != 0.0 || ptd.x != 0.0)
            {
                // Find the angle between the center and the distorted point.
                float angle = atan2(ptd.y, ptd.x);
                
                // Extend a longer line from the center to the new, undistorted point.
                cv::Point2f ptu(ru * cos(angle), ru * sin(angle));
                
                // Adjust relative to the center of the image.
                ptu += center;
                
                map.at<cv::Vec2f>(y,x)[0] = ptu.x;
                map.at<cv::Vec2f>(y,x)[1] = ptu.y;
            }
            
            // Don't distort the center pixel.
            else
            {
                map.at<cv::Vec2f>(y,x)[0] = x;
                map.at<cv::Vec2f>(y,x)[1] = y;
            }
        }
    
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
        
        for (int r=40; r<frame.rows; r+=40)
            line(frame, cv::Point(0,r), cv::Point(frame.cols,r), cv::Scalar(0,0,255), 1);
        for (int c=40; c<frame.cols; c+=40)
            line(frame, cv::Point(c,0), cv::Point(c,frame.rows), cv::Scalar(0,0,255), 1);
        
        cv::remap(frame, frameDistorted, map, cv::noArray(), CV_INTER_LINEAR);
        
        cv::imshow("Camera", frameDistorted);
    } while (cv::waitKey(1) != 27);
}
