# Linux

## Linux VM


**Create VM**
* Open the Oracle VM VirtualBox Manger
* Press "New"
  * Name: Ubuntu OpenCV
  * Type: Linux, Version: Ubuntu (64-bit)
  * RAM: 4096 MB
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



**Shared Clipboard, Drag'n'Drop**
* Settings > General > Advanced
  * Shared Clipboard: Bidirectional
  * Drag'n'Drop: Bidirectional
* From a terminal, type:
  * sudo VBoxClient-all stop
  * sudo VBoxClient-all start
  * Reboot the virtual machine


**Shared Folders**
* Check: Auto-mount and Make Permanent

## cmake-gui

## VTK

## Cuda
https://developer.nvidia.com/cuda-80-ga2-download-archive
cuda-repo-ubuntu1604-8-0-local-ga2_8.0.61-1_amd64.deb


## OpenCV
