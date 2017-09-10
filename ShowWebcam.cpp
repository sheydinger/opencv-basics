#include <iostream>
#include <time.h>
#include "opencv2/opencv.hpp"

int main(int argc, const char * argv[]) {
    
    int frameCount = 0;
    clock_t start = clock();
    std::cout << start << std::endl;
    
    cv::Mat frame;
    
    cv::VideoCapture cap(0);
    
    std::cout << "FPS " << cap.get(CV_CAP_PROP_FPS) << " FPS\n";
    std::cout << "WIDTH " << cap.get(CV_CAP_PROP_FRAME_WIDTH) << "\n";
    std::cout << "HEIGHT " << cap.get(CV_CAP_PROP_FRAME_HEIGHT) << "\n";
    
    while (1)
    {
        cap.read(frame);
        
        cv::imshow("Camera", frame);
        
        // Press ESC to exit.
        if (cv::waitKey(1) == 27)
            exit(0);
                
        frameCount++;
        if (frameCount % 20 == 0)
            std::cout << ((float) frameCount / ((float) (clock() - start) / (float) 1000000.f)) << "\n";
    };
    
    return 0;
}
