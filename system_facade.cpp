#include "system_facade.h"
using namespace facade;


//media_manager methods
string system_facade::readFromHistory(){
    return mediaManager.readFromHistory();
}
string system_facade::readFromAvailableMedias(){
    return mediaManager.readFromAvailableMedias();
}
string system_facade::readFromFavouritePlayList(){
    return mediaManager.readFromFavouritePlayList();
}
void system_facade::setCurrentPlayList(int i){
    mediaManager.setCurrentPlayList(i);
}
string system_facade::getMediaWithIndex(int i){
    return mediaManager.getMediaWithIndex(i);
}
int system_facade::findMedia(string s){
    return mediaManager.findMedia(s);
}
void system_facade::addToFavouritePlayList(string s){
    mediaManager.addToFavouritePlayList(s);
}
void system_facade::deleteFromFavouritePlayList(string s){
    mediaManager.deleteFromFavouritePlayList(s);
}

//media_reader methods
void system_facade::StartPlayingMedia(){
    mediaReader.StartPlayingMedia();
}
void system_facade::Initialize(string path){
    mediaReader.Initialize(path);
}
void system_facade::volume_down(){
    mediaReader.volume_down();
}
void system_facade::volume_up(){
    mediaReader.volume_up();
}
void system_facade::play_pause(){
    mediaReader.play_pause();
}
void system_facade::playing_speed_up(){
    mediaReader.playing_speed_up();
}
void system_facade::playing_speed_down(){
    mediaReader.playing_speed_down();
}
void system_facade::reverse_playing_direction(){
    mediaReader.reverse_playing_direction();
}
gint64 system_facade::get_time(){
    return mediaReader.get_time();
}
gint64 system_facade::getMediaLength(){
    return mediaReader.getMediaLength();
}
void system_facade::shutdown(){
    mediaReader.shutdown();
}

//device_manager methods
string system_facade::detectDevices(){
    return deviceManager.detectDevices();
}

//usb_manager methods
string system_facade::mountfunc(string detectedDevice,string path){
    return usbManager.mountfunc(detectedDevice,path);
}
string system_facade::umountfunc(string path){
    return usbManager.umountfunc(path);
}
string system_facade::saveDir(string path){
    return usbManager.saveDir(path);
}
void system_facade::deleteCache(){
    usbManager.deleteCache();
}

//audioDevices_manager methods
void system_facade::changeOutput(char oldID,char newID){
    audioDevicesManager.changeOutput(oldID,newID);
}
string system_facade::getAudioDevices(){
    return audioDevicesManager.getAudioDevices();
}


//bt_manager methods
string system_facade::connect(string address){
    return btManager.connect(address);
}
string system_facade::disconnect(string address){
    return btManager.disconnect(address);
}
string system_facade::scanOn(){
    return btManager.scanOn();
}
string system_facade::scanOff(){
    return btManager.scanOff();
}
string system_facade::powerOn(){
    return btManager.powerOn();
}
string system_facade::powerOff(){
    return btManager.powerOff();
}
string system_facade::pair(string address){
    return btManager.pair(address);
}
string system_facade::remove(string address){
    return btManager.remove(address);
}
string system_facade::trust(string address){
    return btManager.trust(address);
}
string system_facade::untrust(string address){
    return btManager.untrust(address);
}
string system_facade::devices(){
    return btManager.devices();
}
string system_facade::info(string address){
    return btManager.info(address);
}
string system_facade::agentOn(string capability){
    return btManager.agentOn(capability);
}
string system_facade::agentOff(string capability){
    return btManager.agentOff(capability);
}
string system_facade::getScannedDevices(){
    return btManager.getScannedDevices();
}

