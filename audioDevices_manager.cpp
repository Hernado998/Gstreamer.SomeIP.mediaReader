#include "audioDevices_manager.h"

using namespace audioDevices;
string execute(const std::string& command) {
    system((command + " > temp.txt").c_str()); // execute aplay -l command and save output in temp.txt
 
    std::ifstream ifs("temp.txt"); // open temp file 
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close(); // must close the inout stream so the file can be cleaned up
    if (std::remove("temp.txt") != 0) {
        perror("Error deleting temporary file"); // return the error if exists 
    }
    return ret; // return data inside the temp file
}

void audioDevices_manager::changeOutput(char oldID,char newID){
    char id1=oldID,id2=newID;

    string strReplace1 = "defaults.ctl.card "; 
    strReplace1.insert(18,1,id1); // defining the old line with the old id that we want to change
    string strReplace2 = "defaults.pcm.card ";
    strReplace2.insert(18,1,id1); // defining the old line with the old id that we want to change


    
    string strNew1 = "defaults.ctl.card ";
    strNew1.insert(18,1,id2); // defining the new line that we want to add
    string strNew2 = "defaults.pcm.card ";
    strNew2.insert(18,1,id2); // defining the new line that we want to add


    ifstream filein("/usr/share/alsa/alsa.conf"); //File to read from
    ofstream fileout("/usr/share/alsa/alsa0.conf"); //Temporary file
    if(!filein || !fileout)
    {
        cout << "Error opening files!" << endl; //output error if occurs
    }

    string strTemp;
    while(getline(filein, strTemp))
    {
        if(strTemp == strReplace1){ //if the current line is equal to the line 1 we want to change 
            strTemp = strNew1; //update current line with line 1
        }
        if(strTemp == strReplace2){ //if the current line is equal to the line 2 we want to change 
            strTemp = strNew2; //update current line with line 2
        }
        strTemp += "\n";
        fileout << strTemp; //add updated line to output file
    }
    remove("/usr/share/alsa/alsa.conf"); //delete original file
    rename("/usr/share/alsa/alsa0.conf","/usr/share/alsa/alsa.conf"); //create a new file with updated lines
}
string audioDevices_manager::getAudioDevices(){
    return execute("aplay -l"); //execute apaly -l to get the available audio output devices
}