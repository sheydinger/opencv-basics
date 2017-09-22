#include "opencv2/opencv.hpp"

/*
 * Objective: Provide sliders to vary the ksize and sigma of a Gaussian filter,
 * showing the resulting Gaussian coefficients in the console log.  This
 * indicates the internal workings of GaussianBlur().
 *
 */

// Maps to 1, 3, 5, 7, etc.
int ksizeSlider = 2;

// Maps to double 0.5, 1.0, 1.5, 2.0, 2.5, etc.
int sigmaSlider = 1;

int typeSlider = 0;


void on_trackbar( int, void* )
{
    int ksize = ksizeSlider * 2 + 1;
    double sigma = 0.5 * sigmaSlider + 0.5;
    
    // Map the int trackbar values to valid values for getGaussianKernel.
    std::cout << "ksizes: " << ksize << " sigma: " << sigma << std::endl;
    
    // The kx1 Gaussian coefficients, and the sum of all coefficients.
    cv::Mat kernel, sum;
    
    switch (typeSlider)
    {
        case 0:
            kernel = cv::getGaussianKernel(ksize, sigma, CV_64F);
            break;
        case 1:
        default:
            kernel = cv::getGaussianKernel(ksize, sigma, CV_32F);
            
    }
    std::cout << "kernel: " << std::endl << kernel << std::endl;
    
    // Add all rows.  0 parameter (3rd) means reduce to a single row.
    cv::reduce(kernel, sum, 0, CV_REDUCE_SUM);
    
    // The coefficients are normalized to sum to 1.
    std::cout << "sum: " << sum << std::endl << std::endl;
}

int main(int argc, const char * argv[]) {
    
    cv::namedWindow("getGaussianKernel", 1);
    cv::createTrackbar("ksize", "getGaussianKernel", &ksizeSlider, 10, on_trackbar);
    cv::createTrackbar("sigma", "getGaussianKernel", &sigmaSlider, 19, on_trackbar);
    cv::createTrackbar("CV_64F, CV_32F", "getGaussianKernel", &typeSlider, 1, on_trackbar);
    
    on_trackbar( 0, 0);
    
    cv::waitKey(0);
}
