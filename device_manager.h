#include <bits/stdc++.h>
#include <experimental/filesystem>
#include<sys/mount.h> 
#define BITS 8
using namespace std;
namespace fs = std::experimental::filesystem;
#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H
/*************************************************************************
* This class return the name of the detected usb device
***************************************************************************/
namespace device{
    class device_manager{
        public:
            string detectDevices(); 
        
    };
}
#endif