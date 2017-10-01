#include "opencv2/opencv.hpp"

/*
 * Objective: Find corresponding points in two stereo frames and triangulate.
 * Display the points in rainbow colors to indicate depth.
 */


int main(int argc, const char * argv[]) {
    
    // Retrieve the camera matrices.
    cv::FileStorage fs;
    fs.open("CameraMatricesStereo.yaml", cv::FileStorage::READ);
    
    if (!fs.isOpened())
    {
        std::cout << "Cannot find CameraMatricesStereo.yaml" << std::endl;
        exit(1);
    }
    
    cv::Mat cameraMatrixL, distCoeffsL;
    cv::Mat cameraMatrixR, distCoeffsR;
    cv::Size chessboardSize;
    cv::Size imageSize;
    cv::Mat R, T, E, F;
    
    fs["cameraMatrixL"] >> cameraMatrixL;
    fs["distCoeffsL"] >> distCoeffsL;
    fs["cameraMatrixR"] >> cameraMatrixR;
    fs["distCoeffsR"] >> distCoeffsR;
    fs["chessboardSize"] >> chessboardSize;
    fs["imageSize"] >> imageSize;
    fs["R"] >> R;
    fs["T"]
