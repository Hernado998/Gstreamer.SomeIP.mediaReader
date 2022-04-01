#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <experimental/filesystem>
#include <gstreamer-1.0/gst/gst.h>
#include <gstreamer-1.0/gst/audio/streamvolume.h>
//#include "someip_service.h"
#include <fstream>
#define BITS 8


#ifndef MEDIA_MANAGER_H
#define MEDIA_MANAGER_H
using namespace std;

namespace fs = experimental::filesystem;
/*************************************************************************
* media_manager class is the class responsible of managing the medias in
* the usb stick and it also interacts with cache and playlists
***************************************************************************/
namespace mediamanager{
    class media_manager{
        public:
            
            list<string> *currentPlayList = new list<string>(); //list of medias that the media_manager methods can intercat with
            list<string> *favouritePlayList = new list<string>(); //list of medias in the favourite playlist
            list<string> *historyPlayList = new list<string>(); //list of medias in the history file
            list<string> *availablePlayList = new list<string>(); //list of medias in the usb device

            string readFromHistory(); //this function loads medias paths in the history file into the history medias list
            string readFromAvailableMedias(); //this function loads medias paths in the available file into the available medias list
            string readFromFavouritePlayList(); //this function loads medias paths in the favourite file into the favourite medias list

            void addToFavouritePlayList(string path); // this fonction adds a media to the favourite medias file
            void deleteFromFavouritePlayList(string path); // this function delete a media from the favourite medias file

            string getMediaWithIndex(int index); // this function returns the index of a given media
            int findMedia(string path); // this function returns the name of a media with a given index

            void setCurrentPlayList(int c); // this function set a pointer on the wanted playlist 0:available list/ 1:history list/ 2: favourite list

            void cleaner(); // this function delete duplicates from favourite list
    };
}
#endif