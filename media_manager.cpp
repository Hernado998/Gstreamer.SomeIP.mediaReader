#include "media_manager.h"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace mediamanager;

int contains(list<string> *listOfElements, string element)
{
    auto loe_front = listOfElements->begin();
    for(int i=0;i<listOfElements->size();i++){
        advance(loe_front,i);
        string val= *loe_front;
        if(val.compare(element)==0){
            return i;
        }
    }
    return -1;
}


string media_manager::readFromHistory(){
    ifstream my_file;
    string myLine;
    my_file.open("historylist.txt");
    string s="";
    if(my_file.is_open())
    {
        // Keep reading the file
        while(getline(my_file, myLine))
        {
            // print the line on the standard output
            cout << myLine << endl;
            s+=myLine+"\n";
            historyPlayList->push_back(myLine);
        }
        my_file.close();    
    }
    else
    {
        cout << "Unable to open the history file!"<<endl;
    }
    return s;
}
string media_manager::readFromAvailableMedias(){
    ifstream my_file;
    string myLine;
    string s="";
    my_file.open("mediaslist.txt");
    if(my_file.is_open())
    {
        // Keep reading the file
        while(getline(my_file, myLine))
        {
            // print the line on the standard output
            cout << myLine << endl;
            s+=myLine+"\n";
            availablePlayList->push_back(myLine);
        }
        my_file.close();
    }
    else
    {
        cout << "Unable to open the available medias file!"<<endl;
    }
    return s;
}
string media_manager::readFromFavouritePlayList(){
    ifstream my_file;
    string myLine;
    string s="";
    my_file.open("favourite_medialist.txt");
    if(my_file.is_open())
    {
        // Keep reading the file
        while(getline(my_file, myLine))
        {
            // print the line on the standard output
            cout << myLine << endl;
            s+=myLine+"\n";
            favouritePlayList->push_back(myLine);
        }
        my_file.close();
     
    }
    else
    {
        cout << "Unable to open the favourite medias file!"<<endl;
    }
    return s;
}
void media_manager::addToFavouritePlayList(string path){
    ofstream outfile ("favourite_medialist.txt", ios_base::app);
    outfile << path << endl;
    cleaner();
}
void media_manager::deleteFromFavouritePlayList(string path){
    favouritePlayList->remove(path);
}
string media_manager::getMediaWithIndex(int index){
    if(index<currentPlayList->size()){
        auto l_front = currentPlayList->begin();
        advance(l_front, index);
        cout<<*l_front<<endl;
        return *l_front;
    }
    else{
        return "Doesn't exist!";
    }
}
int media_manager::findMedia(string path){
    int result = contains(currentPlayList, path);
    cout<<result<<endl;
    return result;
}
void media_manager::setCurrentPlayList(int c){
    if(c==0){
        this->currentPlayList=this->availablePlayList;
        cout<<"Setting current play list to available"<<endl;
    }
    if(c==1){
        this->currentPlayList=this->historyPlayList;
        cleaner();
        cout<<"Setting current play list to history"<<endl;
    }
    if(c==2){
        this->currentPlayList=this->favouritePlayList;
        cout<<"Setting current play list to favourite"<<endl;
    }
}
void media_manager::cleaner(){
    auto loe_front = favouritePlayList->begin();
    auto loe_after = favouritePlayList->begin();
    for(int i=0;i<favouritePlayList->size();i++){
        advance(loe_front,i);advance(loe_front,i+1);
        string val= *loe_front;string vala= *loe_after;
        cout<<val+"..... "+vala<<endl;
        if(val.compare(vala)==0){
            favouritePlayList->remove(val);
            cout<<val+" duplicate deleted from favourite list"<<endl;
        }
    }
}

