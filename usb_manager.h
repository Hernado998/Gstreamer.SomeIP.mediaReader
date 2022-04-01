#include <bits/stdc++.h>
#include <experimental/filesystem>
#include<sys/mount.h> 
#define BITS 8
using namespace std;
namespace fs = std::experimental::filesystem;
#ifndef USB_MANAGER_H
#define USB_MANAGER_H
/*************************************************************************
* usb_manager class is the class responsible of the interaction between the
* usb device and the hosting system
***************************************************************************/
namespace usb{
    class usb_manager{
        public:
            string mountfunc(string device,string path); //mount the usb device into a directory inside the system
            string umountfunc(string path); // unmount the usb device
            string saveDir(string path); //create a cache file of the available medias in the usb device
            void deleteCache(); // delete the cache file
        
    };
}
#endif