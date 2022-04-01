#include "usb_manager.h"
#include<sys/mount.h> 
#include <chrono>
#include <thread>
using namespace usb;

string usb_manager::mountfunc(string device,string path){
    int mountAttempts;
    int status; 
    mountAttempts = 0;
    status = 0;
    string deviceName = device, mountPoint=path, fsType="vfat";
    do
    {   
        status = mount(deviceName.c_str(), mountPoint.c_str(), fsType.c_str(), 0, NULL);
        if(status != 0)
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        mountAttempts++;
    }while(status != 0 && mountAttempts < 3);
    string s=strerror(errno);
    return "USB mount - status = "+s+"\n";
}
string usb_manager::umountfunc(string path){
    int mountAttempts;
    int status;
    do
    {   
        status=umount(path.c_str());
        if(status != 0)
            this_thread::sleep_for(std::chrono::milliseconds(500));
        mountAttempts++;
    }while(status != 0 && mountAttempts < 3);
     
    string s=strerror(errno);
    return "USB unmount - status = "+s+"\n";
}
string usb_manager::saveDir(string path){
    ofstream outfile ("medias.txt");
    for (const auto & entry : fs::directory_iterator(path))
        outfile << entry.path().c_str() << endl;
    outfile.close();

    ifstream my_file;
    ofstream outfile0 ("mediaslist.txt");
    string myLine;
    my_file.open("medias.txt");
    while(getline(my_file, myLine))
    {
        myLine.erase(0,1);
        outfile0<<myLine<<endl;
            
    }
    my_file.close();
    outfile0.close();
    remove("medias.txt");
    return "Cache created";

}
/*
void usb_manager::getfromDir(list<string> *L){
    ifstream my_file;
    string myLine;
    my_file.open("mediaslist.txt");
    if(my_file.is_open())
    {
        // Keep reading the file
        while(getline(my_file, myLine))
        {
            // print the line on the standard output
            //cout << myLine << endl;
            L->push_back(myLine);
            //return myLine;
        }
        // File Close
        my_file.close();
    }
    else
    {
        cout << "Unable to open the cache file!";
    }
}
*/
void usb_manager::deleteCache(){
    int status;
    status = remove("mediaslist.txt");
    if(status==0)
        cout<<"\nCache file Deleted Successfully!";
    else
        cout<<"\nError Occurred!";
    cout<<endl;
}
