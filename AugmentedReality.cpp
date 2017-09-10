#include "opencv2/opencv.hpp"

/*
 * Objective: Show how to read and display frames captured from a webcam,
 * and compute and show the meaasured frame rate.  Press ESC to exit the program.
 */

int main(int argc, const char * argv[]) {
    
    cv::Mat frame;
    
    cv::VideoCapture cap(0);
    
    while (1)
    {
        cap.read(frame);
        
        // Sluggish if the image is too big.
        if (frame.cols > 720 || frame.rows > 720)
            cv::resize(frame, frame, cv::Size(0,0), 0.5, 0.5);
        
        std::vector<cv::Point2f> corners;
        bool patternFound = cv::findChessboardCorners(frame, cv::Size(5,5), corners);
        
        if (patternFound)
            cv::drawChessboardCorners(frame, cv::Size(5,5), cv::Mat(corners), patternFound);
        
        cv::imshow("Camera", frame);
        
        // Press ESC to exit.
        if (cv::waitKey(1) == 27)
            exit(0);
    };
    
    return 0;
}
