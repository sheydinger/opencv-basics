# opencv-basics
Simple demonstrations of basic use of OpenCV

## calib3d
Many of the functions of the calib3d module relate to the pinhole camera model found in the Detailed Description on the
[Camera Calibration](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html) page and below.  Often, you'll have some of the values and want to know which function to use to solve for the unknown.  The table below shows inputs in *italic* and outputs in **bold**.

<div style="font-size: 2.3em">hi</div>

```
  | u |    | fx   0  cx || R R R Tx|| X |
s | v |  = |  0  fy  cy || R R R Ty|| Y |
  | 1 |    |  0   0   1 || R R R Tz|| Z |
                                    | 1 |
```


| Function           | objPts           | pts1/2  | M  | distort | R | T | E | F | H | R1/R2 | P1/P2 | Q | misc
| ------------------ |:-------------:|:-----:|:------:|:-----:|:--:|:--:| -- | -- | -- | -- | -- | -- | ----
| **calib3d**
| calibrateCamera    | *X*   | *1* | **X** | **X** | **X** | **X** |
| projectPoints      | *X*   | **1** | *X* | *X* | *X* | *X*
| stereoCalibrate    | *X*   | *1&2* | **1&2** | **1&2** | **X** | **X** | **X** | **X**
| findEssentialMat   |       | *1&2*  | *foc/pp* |  |  |  | **X** |
| findFundamentalMat   |       | *1&2*  |  |  |  |  |  | **X** |
| findFundamentalMat   |       | *1&2*  |  |  |  |  |  |  | **X** |
| stereoRectify   |     |  | *1&2*  |*1&2*  | *X* | *X*  |  |  |  | **1&2** | **1&2** | **X** |
| stereoRectifyUncalibrated |  | *1&2*  |  |  |  |  |  | *X* | **1&2**
| computeCorrespondEpilines |  | *1*  |  |  |  |  |  | *X* 
| reprojectImageTo3D |  | *disparity* |  |  |  |  |  |  |  |  |  | *X* | **image3d**


