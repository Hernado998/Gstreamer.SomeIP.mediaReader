#include <bits/stdc++.h>
#include <experimental/filesystem>
#include<sys/mount.h> 
#define BITS 8
using namespace std;
namespace fs = std::experimental::filesystem;
#ifndef AUDIODEVICES_MANAGER_H
#define AUDIODEVICES_MANAGER_H
/*************************************************************************
* audioDevices_manager class is a micro service that controls and returns 
* the possible audio output devices.
*
* After accessing /usr/share/alsa/alsa.config we can set the id of the device 
* we want it to be our output device.
*
* Getting the id is by simply executing aplay -l command in order to return 
* informations about the available devices 
***************************************************************************/
namespace audioDevices{
    class audioDevices_manager{
        public:
            void changeOutput(char oldID,char newID); //! changing the audio device output by changing the id
            string getAudioDevices(); //! return the list of the available audio devices 
        
    };
}
#endif