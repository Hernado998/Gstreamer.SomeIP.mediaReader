#include <bits/stdc++.h>
#include <experimental/filesystem>
#include<sys/mount.h> 
#define BITS 8
using namespace std;
#include <chrono>
#include <thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
namespace fs = std::experimental::filesystem;
#ifndef BT_MANAGER_H
#define BT_MANAGER_H
/*************************************************************************
* bt_manager class is a micro service that manages Bluetooth devices communications.
***************************************************************************/
namespace bt{
    class bt_manager{
        public:
            string connect(string address); //Connect device
            string disconnect(string address); //Disconnect device
            string scanOn(); //Scan for devices on
            string scanOff(); //Scan for devices off
            string powerOn();//Set controller power on
            string powerOff(); //Set controller power off
            string pair(string address); //Pair with device
            string remove(string address); //Remove device
            string trust(string address); //Trust device
            string untrust(string address); //Untrust device
            string devices(); //List available devices
            string info(string address); //Device information
            string agentOn(string capability=""); //Enable agent with given capability
            string agentOff(string capability=""); //Disable agent with given capability
            string getScannedDevices();

            void scan_execute(string command);
            string r ="";
            
        
    };
}
#endif