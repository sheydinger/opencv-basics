# opencv-basics
Simple demonstrations of basic use of OpenCV

### 3D to 2D Projection Equation
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
| [stereoCalibrate](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga246253dcc6de2e0376c599e7d692303a)    | *X*   | *1&2* | **1&2** | **1&2** | **X** | **X** | **X** | **X**
| [findEssentialMat](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga0c86f6478f36d5be6e450751bbf4fec0)   |       | *1&2*  | *foc/pp* |  |  |  | **X** |
| [findFundamentalMat](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga8e25cb8c64d8baa4749ca28ff1b0866a)   |       | *1&2*  |  |  |  |  |  | **X** |
| [findHomography](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga4abc2ece9fab9398f2e560d53c8c9780)   |       | *1&2*  |  |  |  |  |  |  | **X** |
| [stereoRectify](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga617b1685d4059c6040827800e72ad2b6)   |     |  | *1&2*  |*1&2*  | *X* | *X*  |  |  |  | **1&2** | **1&2** | **X** |
| [stereoRectifyUncalibrated](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#gaadc5b14471ddc004939471339294f052) |  | *1&2*  |  |  |  |  |  | *X* | **1&2**
| [computeCorrespondEpilines](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga19e3401c94c44b47c229be6e51d158b7) |  | *1*  |  |  |  |  |  | *X* 
| [reprojectImageTo3D](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga1bc1152bd57d63bc524204f21fde6e02) |  | *disparity* |  |  |  |  |  |  |  |  |  | *X* | **image3d**
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
| initUndistortRectifyMap |  |  | *X* | *X* |  |  |  |  |  | *X* | *X* |  | **mapx/y**
| remap |  | *srcImg* |  |  |  |  |  |  |  |  |  |  | *mapx/y***dstImg**
| undistort |  | *srcImg* | *X* | *X* |  |  |  |  |  |  |  |  | **dstImg**
| undistortPoints |  | *X* | *X* | *X* |  |  |  |  |  | *X* | *X* |  | **points**
| warpPerspective |  | *srcImg* |  |  |  |  |  |  | *X* |  |  |  | **dstImg**


