#include "bt_manager.h"

using namespace bt;

bool state=false;

void bt_manager::scan_execute(string command) {
   char buffer[128];
   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   while(!feof(pipe)){
        if (fgets(buffer, 128, pipe) != NULL){
            r+= buffer;
        }
   }
}
string execute(string command) {
   char buffer[128];
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }
   pclose(pipe);
   return result;
}

char *concat(string address){
    const char *word="bluetoothctl ";
    const char *word2=address.c_str();
    char *p = new char[strlen(word)+strlen(word2)+1];
    strcpy(p,word);
    strcat(p,word2);
    return p;
}

string bt_manager::connect(string address){
    return execute(concat("connect "+address));
}
string bt_manager::disconnect(string address){
    return execute(concat("disconnect "+address));
}
string bt_manager::scanOn(){
    state=true;
    scan_execute(concat("scan on"));
    return "Scanning...";
}
string bt_manager::getScannedDevices(){
    //cout<<"rrrrrrrrrrrrg "+r<<endl;
    return r;
}
string bt_manager::scanOff(){
    state=false;
    execute(concat("scan off"));
    return "Scanning stopped";

}
string bt_manager::powerOn(){
    return execute(concat("power on"));
}
string bt_manager::powerOff(){
    return execute(concat("power off"));
}
string bt_manager::pair(string address){
    return execute(concat("pair "+address));
}
string bt_manager::remove(string address){
    return execute(concat("remove "+address));
}
string bt_manager::trust(string address){
    return execute(concat("trust "+address));
}
string bt_manager::untrust(string address){
    return execute(concat("untrust "+address));
}
string bt_manager::devices(){
    return execute("bluetoothctl devices");
}
string bt_manager::info(string address){
    return execute("bluetoothctl info "+address);
}
string bt_manager::agentOn(string capability){
    return execute(concat("agent on"+capability));
}
string bt_manager::agentOff(string capability){
    return execute(concat("agent off"+capability));
}