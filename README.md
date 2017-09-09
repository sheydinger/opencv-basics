# opencv-basics
Simple demonstrations of basic use of OpenCV

## calib3d
Many of the functions of the calib3d module relate to the pinhole camera model found in the Detailed Description on the
[Camera Calibration](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html) page and below.  Often, you'll have some of the values and want to know which function to use to solve for the unknown.  The table below shows inputs in *italic* and outputs in **bold**.


```
  | u |    | fx   0  cx || R R R Tx|| X |
s | v |  = |  0  fy  cy || R R R Ty|| Y |
  | 1 |    |  0   0   1 || R R R Tz|| Z |
                                    | 1 |
```


| Function           | objPts           | pts1/2  | M  | distort | R | T | E | F | H | R1/R2 | P1/P2 | Q | misc
| ------------------ |:-------------:|:-----:|:------:|:-----:|:--:|:--:| -- | -- | -- | -- | -- | -- | ----
| **[calib3d](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html)**
| [calibrateCamera](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga3207604e4b1a1758aa66acb6ed5aa65d)    | *X*   | *1* | **X** | **X** | **X** | **X** |
| [projectPoints](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga1019495a2c8d1743ed5cc23fa0daff8c)      | *X*   | **1** | *X* | *X* | *X* | *X*
| stereoCalibrate    | *X*   | *1&2* | **1&2** | **1&2** | **X** | **X** | **X** | **X**
| findEssentialMat   |       | *1&2*  | *foc/pp* |  |  |  | **X** |
| findFundamentalMat   |       | *1&2*  |  |  |  |  |  | **X** |
| findHomography   |       | *1&2*  |  |  |  |  |  |  | **X** |
| stereoRectify   |     |  | *1&2*  |*1&2*  | *X* | *X*  |  |  |  | **1&2** | **1&2** | **X** |
| stereoRectifyUncalibrated |  | *1&2*  |  |  |  |  |  | *X* | **1&2**
| computeCorrespondEpilines |  | *1*  |  |  |  |  |  | *X* 
| reprojectImageTo3D |  | *disparity* |  |  |  |  |  |  |  |  |  | *X* | **image3d**
|  |  |  |  |  |  |  |  |  |  |  |  |  | 
| decomposeEssentialMat |  |  |  |  | *1&2* | *X* | **X** |  |  |  |  |  | 
| decomposeHomographyMat |  |  | *X(K)* |  | **multiple** | **multiple** |  |  | *X* |  |  |  | 
| decomposeProjectionMatrix |  |  | **X** |  | **X** | **X** |  |  |  |  | *P* |  | 
|  |  |  |  |  |  |  |  |  |  |  |  |  | 
| recoverPose |  | *1&2* | foc/pp |  | **X** | **X** | *X* |  |  |  |  |  | 
| triangulatePoints |  | *1&2* |  |  |  |  |  |  |  |  | *P1&P2* |  | **points4D**
| solvePnP | *X* | *1* | *X* | *X* | **X** | **X** |  |  |  |  |  |  | 
| solvePnPRansac | *X* | *1* | *X* | *X* | **X** | **X** |  |  |  |  |  |  | 
|   |  |  |  |  |  |  |  |  |  |  |  |  | 
| **[core](http://docs.opencv.org/3.2.0/d0/de1/group__core.html)**
| perspectiveTransform |  | *X* |  |  |  |  |  |  | *X* |  |  |  | **points**
|   |  |  |  |  |  |  |  |  |  |  |  |  | 
| **[imgproc](http://docs.opencv.org/3.2.0/d7/dbd/group__imgproc.html)**
 


