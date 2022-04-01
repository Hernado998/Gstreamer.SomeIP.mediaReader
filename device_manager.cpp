
#include <sys/statvfs.h>
#include <bits/stdc++.h>
#include <experimental/filesystem>
#include<sys/mount.h> 
#include "device_manager.h"
#define BITS 8
using namespace device;
using namespace std;
namespace fs = std::experimental::filesystem;
using FILEPTR = std::unique_ptr<std::FILE, decltype(&::std::fclose)>;


string device_manager::detectDevices(){
    FILEPTR f{nullptr, &::fclose};
    FILEPTR g{nullptr, &::fclose};
    FILEPTR h{nullptr, &::fclose};
    f.reset(fopen("/dev/sdb1", "r"));
    g.reset(fopen("/dev/sda1", "r"));
    h.reset(fopen("/dev/sdc1", "r"));
    auto val="nothing";
    if ( nullptr != h ){
         cout << "sdc detected!" << endl;
         val="/dev/sdc1";
         return val;
     }
     if ( nullptr != f ){
         cout << "sdb detected!" << endl;
         val="/dev/sdb1";
         return val;
     }
     if (nullptr != g) {
         cout << "sda detected!" << endl;
         val="/dev/sda1";
         return val;
     }
     if ( nullptr == h ){
        auto err = errno;
        cerr << "unable to open /dev/sdc: " << err << ": " << strerror(err) << endl;
        val="nothing";
     }
     if( nullptr == f ){
         auto err = errno;
        cerr << "unable to open /dev/sdb: " << err << ": " << strerror(err) << endl;
        val="nothing";
     }
    if ( nullptr == g ){
        auto err = errno;
        cerr << "unable to open /dev/sda: " << err << ": " << strerror(err) << endl;
        val="nothing";
     }
     if( nullptr == f ){
         auto err = errno;
        cerr << "unable to open /dev/sdb: " << err << ": " << strerror(err) << endl;
        val="nothing";
     }
     else{
         val="nothing";
     }
     return val;
}