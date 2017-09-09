# opencv-basics
Simple demonstrations of basic use of OpenCV

## Documentation (3.2) Links
Structures
- [Affine3](http://docs.opencv.org/3.2.0/dd/d99/classcv_1_1Affine3.html)
- [Mat](http://docs.opencv.org/3.2.0/d3/d63/classcv_1_1Mat.html)
- [Rect](http://docs.opencv.org/3.2.0/d2/d44/classcv_1_1Rect__.html#afb53dd5c7f9a57ecb3d50d62d2d6dd14)
- [Size](http://docs.opencv.org/3.2.0/d6/d50/classcv_1_1Size__.html)
- [RotatedRect](http://docs.opencv.org/3.2.0/db/dd6/classcv_1_1RotatedRect.html)
* Image Processing
  * [Image Filtering](http://docs.opencv.org/3.2.0/d4/d86/group__imgproc__filter.html)
    * [blur](http://docs.opencv.org/3.2.0/d4/d86/group__imgproc__filter.html#ga8c45db9afe636703801b0b2e440fce37)
    * [dilate](http://docs.opencv.org/3.2.0/d4/d86/group__imgproc__filter.html#ga4ff0f3318642c4f469d0e11f242f3b6c)
    * [erode](http://docs.opencv.org/3.2.0/d4/d86/group__imgproc__filter.html#gaeb1e0c1033e3f6b891a25d0511362aeb)
    * [GaussianBlur](http://docs.opencv.org/3.2.0/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1)
  * [Geometric Image Transformations](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html)
    * [getAffineTransform](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga8f6d378f9f8eebb5cb55cd3ae295a999)
    * [getDefaultNewCameraMatrix](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga744529385e88ef7bc841cbe04b35bfbf)
    * [getPerspectiveTransform](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga8c1ae0e3589a9d77fffc962c49b22043)
    * [getRectSubPix](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga77576d06075c1a4b6ba1a608850cd614)
    * [remap](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#gab75ef31ce5cdfb5c44b6da5f3b908ea4)
    * [resize](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga47a974309e9102f5f08231edc7e7529d)
    * [undistort](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga69f2545a8b62a6b0fc2ee060dc30559d) 
    * [undistortPoints](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga55c716492470bfe86b0ee9bf3a1f0f7e)
    * [warpAffine](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga0203d9ee5fcd28d40dbc4a1ea4451983)
    * [warpPerspective](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#gaf73673a7e8e18ec6963e3774e6a94b87)
  * [Miscellaneous Image Transformation](http://docs.opencv.org/3.2.0/d7/d1b/group__imgproc__misc.html)
    * [adaptiveThreshold](http://docs.opencv.org/3.2.0/d7/d1b/group__imgproc__misc.html#ga72b913f352e4a1b1b397736707afcde3)
    * [cvtColor](http://docs.opencv.org/3.2.0/d7/d1b/group__imgproc__misc.html#ga397ae87e1288a81d2363b61574eb8cab)
    * [threshold](http://docs.opencv.org/3.2.0/d7/d1b/group__imgproc__misc.html#gae8a4a146d1ca78c626a53577199e9c57)
  * [Drawing Functions](http://docs.opencv.org/3.2.0/d6/d6e/group__imgproc__draw.html)
    * [drawContours](http://docs.opencv.org/3.2.0/d6/d6e/group__imgproc__draw.html#ga746c0625f1781f1ffc9056259103edbc)
  * [Color Maps in OpenCV](http://docs.opencv.org/3.2.0/d3/d50/group__imgproc__colormap.html)
    * [applyColorMap](http://docs.opencv.org/3.2.0/d3/d50/group__imgproc__colormap.html#gadf478a5e5ff49d8aa24e726ea6f65d15)
  * [Histograms](http://docs.opencv.org/3.2.0/d6/dc7/group__imgproc__hist.html)
    * [calcBackProject](http://docs.opencv.org/3.2.0/d6/dc7/group__imgproc__hist.html#ga3a0af640716b456c3d14af8aee12e3ca)
    * [calcHist](http://docs.opencv.org/3.2.0/d6/dc7/group__imgproc__hist.html#ga4b2b5fd75503ff9e6844cc4dcdaed35d)
    * [compareHist](http://docs.opencv.org/3.2.0/d6/dc7/group__imgproc__hist.html#gaf4190090efa5c47cb367cf97a9a519bd)
    * [equalizeHist](http://docs.opencv.org/3.2.0/d6/dc7/group__imgproc__hist.html#ga7e54091f0c937d49bf84152a16f76d6e)
  * [Structural Analysis and Shape Descriptors](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html)
    * [findContours](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga17ed9f5d79ae97bd4c7cf18403e1689a)
    * [approxPolyDP](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga0012a5fdaea70b8a9970165d98722b4c)
    * [arcLength](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga8d26483c636be6b35c3ec6335798a47c)
    * [contourArea](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga2c759ed9f497d4a618048a2f56dc97f1)
    * [pointPolygonTest](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga1a539e8db2135af2566103705d7a5722)
    * [HuMoments](http://docs.opencv.org/3.2.0/d3/dc0/group__imgproc__shape.html#ga6d6ac1b519cba25190119afe3a52c1cc)
  * [Motion Analysis and Object Tracking](http://docs.opencv.org/3.2.0/d7/df3/group__imgproc__motion.html)
    * [phaseCorrelate](http://docs.opencv.org/3.2.0/d7/df3/group__imgproc__motion.html#ga552420a2ace9ef3fb053cd630fdb4952)
  * [Feature Detection](http://docs.opencv.org/3.2.0/dd/d1a/group__imgproc__feature.html)
    * [Canny](http://docs.opencv.org/3.2.0/dd/d1a/group__imgproc__feature.html#ga04723e007ed888ddf11d9ba04e2232de)
    * [cornerHarris](http://docs.opencv.org/3.2.0/dd/d1a/group__imgproc__feature.html#gac1fc3598018010880e370e2f709b4345)
    * [goodFeaturesToTrack](http://docs.opencv.org/3.2.0/dd/d1a/group__imgproc__feature.html#ga1d6bb77486c8f92d79c8793ad995d541)
    * [HoughLines](http://docs.opencv.org/3.2.0/dd/d1a/group__imgproc__feature.html#ga46b4e588934f6c8dfd509cc6e0e4545a)
  * [Object Detection](http://docs.opencv.org/3.2.0/df/dfb/group__imgproc__object.html)
    * [matchTemplate](http://docs.opencv.org/3.2.0/df/dfb/group__imgproc__object.html#ga586ebfb0a7fb604b35a23d85391329be)
* Calib3d
  * [Camera Calibration and 3D Reconstruction](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html)
    * [calibrateCamera](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga3207604e4b1a1758aa66acb6ed5aa65d)
    * [findChessboardCorners](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga93efa9b0aa890de240ca32b11253dd4a)


## 3D to 2D Projection Equation
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
| **calib3d**
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
| [decomposeEssentialMat](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga54a2f5b3f8aeaf6c76d4a31dece85d5d) |  |  |  |  | *1&2* | *X* | **X** |  |  |  |  |  | 
| [decomposeHomographyMat](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga7f60bdff78833d1e3fd6d9d0fd538d92) |  |  | *X(K)* |  | **multiple** | **multiple** |  |  | *X* |  |  |  | 
| [decomposeProjectionMatrix](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#gaaae5a7899faa1ffdf268cd9088940248) |  |  | **X** |  | **X** | **X** |  |  |  |  | *P* |  | 
|  |  |  |  |  |  |  |  |  |  |  |  |  | 
| [recoverPose](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#gadb7d2dfcc184c1d2f496d8639f4371c0) |  | *1&2* | foc/pp |  | **X** | **X** | *X* |  |  |  |  |  | 
| [triangulatePoints](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#gad3fc9a0c82b08df034234979960b778c) |  | *1&2* |  |  |  |  |  |  |  |  | *P1&P2* |  | **points4D**
| [solvePnP](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga549c2075fac14829ff4a58bc931c033d) | *X* | *1* | *X* | *X* | **X** | **X** |  |  |  |  |  |  | 
| [solvePnPRansac](http://docs.opencv.org/3.2.0/d9/d0c/group__calib3d.html#ga50620f0e26e02caa2e9adc07b5fbf24e) | *X* | *1* | *X* | *X* | **X** | **X** |  |  |  |  |  |  | 
|   |  |  |  |  |  |  |  |  |  |  |  |  | 
| **core Operations on Arrays**
| [perspectiveTransform](http://docs.opencv.org/3.2.0/d2/de8/group__core__array.html#gad327659ac03e5fd6894b90025e6900a7) |  | *X* |  |  |  |  |  |  | *X* |  |  |  | **points**
|   |  |  |  |  |  |  |  |  |  |  |  |  | 
| Function           | objPts           | pts1/2  | M  | distort | R | T | E | F | H | R1/R2 | P1/P2 | Q | misc
| **imgproc Geometric Image Transformations**
| [initUndistortRectifyMap](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga7dfb72c9cf9780a347fbe3d1c47e5d5a) |  |  | *X* | *X* |  |  |  |  |  | *X* | *X* |  | **mapx/y**
| [remap](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#gab75ef31ce5cdfb5c44b6da5f3b908ea4) |  | *srcImg* |  |  |  |  |  |  |  |  |  |  | *mapx/y***dstImg**
| [undistort](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga69f2545a8b62a6b0fc2ee060dc30559d) |  | *srcImg* | *X* | *X* |  |  |  |  |  |  |  |  | **dstImg**
| [undistortPoints](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#ga55c716492470bfe86b0ee9bf3a1f0f7e) |  | *X* | *X* | *X* |  |  |  |  |  | *X* | *X* |  | **points**
| [warpPerspective](http://docs.opencv.org/3.2.0/da/d54/group__imgproc__transform.html#gaf73673a7e8e18ec6963e3774e6a94b87) |  | *srcImg* |  |  |  |  |  |  | *X* |  |  |  | **dstImg**


