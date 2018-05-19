#include "opencv2/opencv.hpp"

/*
 * Objective: Show how to use ORB to find feature matches between two
 * images.  Use live video streams and an approximate nearest neighbor
 * search comparison algorithm (locally sensitive hash).
 *
 */

// The webcam images might be big on the screen.  Use this to fit.
double imageScaleFactor = 0.5;

int main(int argc, const char * argv[]) {
    
    cv::VideoCapture cap(0);

    // ORB STUFF
    // =========
    
    std::vector<cv::KeyPoint> kptTrain, kptQuery;
    cv::Mat dscTrain, dscQuery;
    
    cv::Ptr<cv::ORB> orb = cv::ORB::create();

    // Lsh is a technique for building an index with binary features.  Not
    // all query descriptors will be found due to the nature of the approximate
    // nearest neighbor.
    cv::FlannBasedMatcher matcher(new cv::flann::LshIndexParams(12,20,2));

    // This can be used instead of the FlannBasedMatcher, but is slower.  With
    // binary features such as ORB features, a Hamming distance (the number
    // of different bits) is used as opposed to a Euclidean distance.  Every
    // query will have a match.
//    cv::BFMatcher matcher(cv::NORM_HAMMING);

    // Filter the matches by "distance" to show only matches that are
    // likely legitimate.
    std::vector<cv::DMatch> matches, goodMatches;


    // CAPTURE TRAIN IMAGE
    // ===================

    cv::Mat imgTrain;
    
    int ch;

    // Keep showing a live stream until the user presses the space bar
    // to establish a train image.
    while (true)
    {
        cap.read(imgTrain);
        cv::resize(imgTrain, imgTrain, cv::Size(0,0), imageScaleFactor, imageScaleFactor);
        
        orb->detectAndCompute(imgTrain, cv::noArray(), kptTrain, dscTrain);
        cv::drawKeypoints(imgTrain, kptTrain, imgTrain, cv::Scalar(0,0,255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
        
        cv::imshow("Train", imgTrain);
        
        ch = cv::waitKey(100);
        if (ch == 0x1b)
            return 1;
        else if (ch == ' ')
            break;
    }

    // The train keypoints should be added to the matcher once, and an index
    // built once, i.e. the matcher is trained on the train descriptors.
    // Looking up in the "database" is therefore faster than brute force
    // comparison of all train descriptors but not necessarily as accurate
    // since not all train descriptors are guaranteed to be considered.
    matcher.add(dscTrain);
    matcher.train();

    
    // CAPTURE QUERY IMAGE
    // ===================
    
    cv::Mat imgQuery, imgMatch;
    
    while (true)
    {
        cap.read(imgQuery);
        cv::resize(imgQuery, imgQuery, cv::Size(0,0), imageScaleFactor, imageScaleFactor);

        orb->detectAndCompute(imgQuery, cv::noArray(), kptQuery, dscQuery);
        
        // MATCH
        // =====
        
        matcher.match(dscQuery, matches);
        
        goodMatches.clear();
        for (int m=0; m<matches.size(); m++)
        {
            if (matches[m].distance < 40)
                goodMatches.push_back(matches[m]);
        }
        
        // The number of matches may be less than the number of queries because
        // Lsh is an "approximate" nearest neighbor algorithm.  It uses an index,
        // and depending on the Lsh bucket contents a best match might not be found.
        std::cout << dscQuery.rows << " " << matches.size() << " " << goodMatches.size() << std::endl;

        cv::drawMatches(imgQuery, kptQuery, imgTrain, kptTrain, goodMatches, imgMatch);
        cv::imshow("Matches", imgMatch);
        
        ch = cv::waitKey(100);
        if (ch == 0x1b)
            return 1;
    }

    return 0;
}
