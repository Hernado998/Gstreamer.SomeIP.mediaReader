#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <experimental/filesystem>
#include <fstream>
#include "media_reader.h"
#include "media_manager.h"
#include "usb_manager.h"
#include "device_manager.h"
#include "audioDevices_manager.h"
#include "bt_manager.h"
//#include "someip_service.h"



using namespace std;
using namespace media;
using namespace usb;
using namespace device;
using namespace mediamanager;
using namespace audioDevices;
using namespace bt;

#define BITS 8
using namespace std;
namespace fs = experimental::filesystem;
#ifndef SYSTEM_FACADE_H
#define SYSTEM_FACADE_H
/*************************************************************************
* system_facade class is the class responsible of hiding the complexities of 
* the system and provides a simpler interface to the client. 
* It is a single wrapper class that contains a set of members 
* required by the client. These members access the system on behalf of the 
* facade client and hide the implementation details. 
***************************************************************************/
namespace facade{
    class system_facade{
        public:
            
            string request;
            string response;
            bool state = false; 
            //string detectedDevice;
            

            //media_manager methods
            string readFromHistory();
            string readFromAvailableMedias();
            string readFromFavouritePlayList();
            void addToFavouritePlayList(string path);
            void deleteFromFavouritePlayList(string path);
            string getMediaWithIndex(int index);
            int findMedia(string path);
            void setCurrentPlayList(int c);
            void cleaner();

            //media_reader methods
            void Initialize(string path);
            void StartPlayingMedia();
            void MediaReader();
            gint64 get_time();
            gint64 getMediaLength();
            void playing_speed_up();
            void playing_speed_down();
            void reverse_playing_direction();
            void play_pause();
            void volume_down();
            void volume_up();
            void shutdown();

            //device_manager methods
            string detectDevices();

            //usb_manager methods
            string mountfunc(string device,string path);
            string umountfunc(string path);
            string saveDir(string path);
            void deleteCache();

            //audioDevices_manager methods
            void changeOutput(char oldID,char newID);
            string getAudioDevices();

            //bt_manager methods
            string connect(string address);
            string disconnect(string address);
            string scanOn();
            string scanOff();
            string powerOn();
            string powerOff();
            string pair(string address);
            string remove(string address);
            string trust(string address);
            string untrust(string address);
            string devices();
            string info(string address);
            string agentOn(string capability);
            string agentOff(string capability);
            string getScannedDevices();

        protected:
                media_manager mediaManager;
                media_reader mediaReader;
                usb_manager usbManager;
                device_manager deviceManager;
                audioDevices_manager audioDevicesManager;
                bt_manager btManager;
    };
}

#endif