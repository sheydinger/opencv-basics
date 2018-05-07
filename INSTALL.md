# Linux

## Linux VM

**Create VM**
* Open the Oracle VM VirtualBox Manger
* Press "New"
  * Name and operating system
    * Name: Ubuntu OpenCV
    * Type: Linux, Version: Ubuntu (64-bit)
    * Version: Ubuntu (64-bit)
  * Memory size: 1024 MB
  * Hard disk: Create a virtual hard disk now
  * Hard disk file type: VDI (VirtualBox Disk Image)
  * Storage on physical hard disk: Dynamically allocated
  * File location and size: 80.00 GB (This is a max for dynamic allocations and cannot be reaised later)

**Start VM**
* Click on Ubuntu OpenCV
* Select start-up disk: ubuntu-16.04.3-desktop-amd64.iso
* Welcome: Install Ubuntu
* Preparing to install Ubuntu: Download updates while installing Ubuntu = checked
* Installation type: Erase disk and install Ubuntu
* Who are you: Log in automatically
* After the prompts, restart.
* When asked to remove the medium, just press Enter.

**Restart VM**
* Devices > Insert Guest Additions CD image...
* Run the automatically started software when prompted.

**Shared Clipboard, Drag'n'Drop**
* Settings > General > Advanced
  * Shared Clipboard: Bidirectional
  * Drag'n'Drop: Bidirectional
* Reboot the virtual machine

**Shared Folders**
* Check: Auto-mount and Make Permanent

## git
* sudo apt install git

## cmake-gui
* sudo apt install cmake-gui

## OpenGL
If trying to configure in cmake, will get "Could NOT filnd OpenGL".  Need libgl1-mesa-dev:
* sudo apt install libgl1-mesa-dev

If trying to configure in cmake, will get "X11_Xt_LIB could not be found.  Required for VTK X lib.".  Need libxt-dev:
* sudo apt install libxt-dev

## Netbeans
* Download and install Netbeans 8.2, C/C++ x64

## VTK
Don't get VTK from github.  The tags appear to have some errors.
* Download VTK-7.1.1.zip from https://www.vtk.org/download/ within FireFox, save to file.
* Extract to ~/Documents/VTK-7.1.1
* Create a directory ~/Documents/VTK-7.1.1-build
* Open cmake-gui
  * Where is the source code: ~/Documents/VTK-7.1.1
  * Where to build the binaries: ~/Documents/VTK-7.1.1-build
  * Configure
    * CMAKE_BUILD_TYPE = Release
  * Generate
* From the VTK-7.1.1-build directory:
  * make -j2
  * sudo make install
  
## OpenCV
* cd ~/Documents
* git clone https://github.com/opencv/opencv.git
* git checkout 3.4.1
* git describe
* Create a directory ~/Documents/opencv-3.4.1-release  (This will use -O3)
* Opem cmake-gui
  * Where is the source code: ~/Documents/opencv
  * Where to build the binaries: ~/Documents/opencv-3.4.1-release
  * Configure
    * ENABLE_CXX11 = checked
    * CMAKE_BUILD_TYPE = Release
    * Check the loacation of the VTK
  * Generate
* From the opencv-3.4.1-release directory:
  * make -j2 (A number of processors > 2 may use up all the virtual memory)
  * sudo make install

## CUDA
* sudo apt-get intall build-essential
* In FireFox, navigate to http:s//developer.nvidia.com/cuda-downloads
* Choose Legacy Releases
* CUDA Toolkit 8.0 GA2
* Linux, x86_64, Ubuntu, 16.04, runfile (local)
* Download cuda_8.0.61_375.26_linux.run and Save File
