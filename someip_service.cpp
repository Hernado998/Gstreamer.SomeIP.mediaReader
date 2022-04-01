#include <iomanip>
#include <iostream>
#include <sstream>
#include "someip_service.h"
#include <chrono>
#include <vsomeip/vsomeip.hpp>
#include <sstream>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID 0x5678

//media_manager class IDs
#define SAMPLE_METHOD_ID0001 0x0001
#define SAMPLE_METHOD_ID0002 0x0002
#define SAMPLE_METHOD_ID0003 0x0003
#define SAMPLE_METHOD_ID0004 0x0004
#define SAMPLE_METHOD_ID0005 0x0005
#define SAMPLE_METHOD_ID0006 0x0006
#define SAMPLE_METHOD_ID0007 0x0007
#define SAMPLE_METHOD_ID0008 0x0008

//media_reader class IDs
#define SAMPLE_METHOD_ID0101 0x0101
#define SAMPLE_METHOD_ID0102 0x0102
#define SAMPLE_METHOD_ID0103 0x0103
#define SAMPLE_METHOD_ID0104 0x0104
#define SAMPLE_METHOD_ID0105 0x0105
#define SAMPLE_METHOD_ID0106 0x0106
#define SAMPLE_METHOD_ID0107 0x0107
#define SAMPLE_METHOD_ID0108 0x0108
#define SAMPLE_METHOD_ID0109 0x0109
#define SAMPLE_METHOD_ID0110 0x0110
#define SAMPLE_METHOD_ID0111 0x0111

//device_manager class IDs
#define SAMPLE_METHOD_ID0201 0x0201

//usb_manager class IDs
#define SAMPLE_METHOD_ID0301 0x0301
#define SAMPLE_METHOD_ID0302 0x0302
#define SAMPLE_METHOD_ID0303 0x0303
#define SAMPLE_METHOD_ID0304 0x0304

//audioDevices_manager class IDS
#define SAMPLE_METHOD_ID0401 0x0401
#define SAMPLE_METHOD_ID0402 0x0402

//bt_manager class IDS
#define SAMPLE_METHOD_ID0501 0x0501
#define SAMPLE_METHOD_ID0502 0x0502
#define SAMPLE_METHOD_ID0503 0x0503
#define SAMPLE_METHOD_ID0504 0x0504
#define SAMPLE_METHOD_ID0505 0x0505
#define SAMPLE_METHOD_ID0506 0x0506
#define SAMPLE_METHOD_ID0507 0x0507
#define SAMPLE_METHOD_ID0508 0x0508
#define SAMPLE_METHOD_ID0509 0x0509
#define SAMPLE_METHOD_ID0510 0x0510
#define SAMPLE_METHOD_ID0511 0x0511
#define SAMPLE_METHOD_ID0512 0x0512
#define SAMPLE_METHOD_ID0513 0x0513
#define SAMPLE_METHOD_ID0514 0x0514
#define SAMPLE_METHOD_ID0515 0x0515

using namespace std::this_thread;
using namespace std::chrono;
using std::chrono::system_clock;




void someip_service::on_message001(const std::shared_ptr<vsomeip::message> &_request) {

    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++) {
       ss << char((int)*(its_payload->get_data()+i));
    }
    
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;
    string vout="\nHistory file data:\n";
    
    vout+=SF.readFromHistory();
    
    // Create response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK1";  
    for(int j=0;j<vout.length();j++){
        its_payload_data.push_back(int(vout[j]));
                //cout<<int(vout[j])<<endl;
    }
    
            //oout->message_from_subject_="";
        
        
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();

}
void someip_service::on_message002(const std::shared_ptr<vsomeip::message> &_request) {

    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++) {
       ss << char((int)*(its_payload->get_data()+i));
    }
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;
    string vout="\nFavourite file data:\n";
   
    vout+=SF.readFromFavouritePlayList();
 
    // Create response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK2";  
    for(int j=0;j<vout.length();j++){
        its_payload_data.push_back(int(vout[j]));
                //cout<<int(vout[j])<<endl;
    }
    
            //oout->message_from_subject_="";
        
        
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();

}
void someip_service::on_message003(const std::shared_ptr<vsomeip::message> &_request) {

    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();

    // Get payload
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++) {
       ss << char((int)*(its_payload->get_data()+i));
    }
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;
    string vout="\nAvailable file data:\n";

    vout+=SF.readFromAvailableMedias();
    
    // Create response
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK3";  
    for(int j=0;j<vout.length();j++){
        its_payload_data.push_back(int(vout[j]));
                //cout<<int(vout[j])<<endl;
    }
    
            //oout->message_from_subject_="";
        
        
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
    

}
void someip_service::on_message004(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;
    SF.setCurrentPlayList(stoi(ss.str()));
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Setting current playlist to: "+ss.str();  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message005(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout<<stoi(ss.str())<<endl;
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout=" "+SF.getMediaWithIndex(stoi(ss.str()));
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK5";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message006(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout=to_string(SF.findMedia(ss.str()));
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //string vout="OK6";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message007(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.addToFavouritePlayList(ss.str());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Added to favourite";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message008(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.deleteFromFavouritePlayList(ss.str());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Deleted from favourite";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}


void someip_service::on_message101(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.Initialize(ss.str());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="OK101";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message102(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.StartPlayingMedia();
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="OK102";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message103(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout=to_string(SF.get_time());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //string vout="OK11";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message104(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.volume_up();
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Volume up";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message105(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.volume_down();
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Volume down";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message106(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    try{
        SF.shutdown();
    }
    catch (int e){
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }

    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Media closed !";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message107(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.play_pause();
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="Played/Paused";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message108(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout=to_string(SF.getMediaLength());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data; 
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message109(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.playing_speed_up();
    string vout="OK109";
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data; 
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message110(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.playing_speed_down();
    string vout="OK110";
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data; 
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message111(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    SF.reverse_playing_direction();
    string vout="OK111";
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data; 
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}


void someip_service::on_message201(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    detectedDevice = SF.detectDevices();
    std::cout<<detectedDevice<<std::endl;
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    string vout="\nDetected device name is: "+detectedDevice+"\n";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}


void someip_service::on_message301(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout="\n"+SF.mountfunc(detectedDevice,ss.str())+"\n";
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK17";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message302(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout="\n"+SF.umountfunc(ss.str())+"\n";
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    //vout="OK18";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message303(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;    
    string vout=SF.saveDir(ss.str());
    std::shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> its_payload_data;
    vout="Cache file created Successfully!";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message304(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;
    SF.deleteCache();
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout="Cache file Deleted Successfully!";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message401(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    SF.changeOutput(ss.str()[0],ss.str()[1]);
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout="Output audio device changed!";  
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message402(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.getAudioDevices();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}


void someip_service::on_message501(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.connect(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message502(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.disconnect(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message503(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    
    string vout=SF.scanOn();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();

}
void someip_service::on_message504(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.scanOff();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message505(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.powerOn();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message506(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.powerOff();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message507(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.pair(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message508(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.remove(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message509(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.trust(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message510(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.untrust(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message511(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.devices();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message512(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.info(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message513(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.agentOn(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message514(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.agentOff(ss.str());
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}
void someip_service::on_message515(const std::shared_ptr<vsomeip::message> &_request) {
    std::shared_ptr<vsomeip::payload> its_payload = _request->get_payload();
    vsomeip::length_t l = its_payload->get_length();
    std::stringstream ss;
    for (vsomeip::length_t i=0; i<l; i++)
       ss << char((int)*(its_payload->get_data()+i));
    cout << "SERVICE: Received message with Client/Session ["<< setw(4) << setfill('0') << hex << _request->get_client() << "/"<<setw(4) << setfill('0') << hex << _request->get_session() << "] "<< ss.str()+"\t"<< endl;

    
    shared_ptr<vsomeip::message> its_response = vsomeip::runtime::get()->create_response(_request);
    its_payload = vsomeip::runtime::get()->create_payload();
    vector<vsomeip::byte_t> its_payload_data;
    string vout=SF.getScannedDevices();
    for(int j=0;j<vout.length();j++)
        its_payload_data.push_back(int(vout[j]));
    its_payload->set_data(its_payload_data);
    its_response->set_payload(its_payload);
    app->send(its_response);
    its_payload_data.clear();
}


void someip_service::Init() {
   app = vsomeip::runtime::get()->create_application("World");
   app->init();
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0001, bind(&someip_service::on_message001, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0002, bind(&someip_service::on_message002, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0003, bind(&someip_service::on_message003, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0004, bind(&someip_service::on_message004, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0005, bind(&someip_service::on_message005, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0006, bind(&someip_service::on_message006, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0007, bind(&someip_service::on_message007, this, std::placeholders::_1));
   
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0008, bind(&someip_service::on_message008, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0101, bind(&someip_service::on_message101, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0102, bind(&someip_service::on_message102, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0103, bind(&someip_service::on_message103, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0104, bind(&someip_service::on_message104, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0105, bind(&someip_service::on_message105, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0106, bind(&someip_service::on_message106, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0107, bind(&someip_service::on_message107, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0108, bind(&someip_service::on_message108, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0109, bind(&someip_service::on_message109, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0110, bind(&someip_service::on_message110, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0111, bind(&someip_service::on_message111, this, std::placeholders::_1));

   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0201, bind(&someip_service::on_message201, this, std::placeholders::_1));
   
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0301, bind(&someip_service::on_message301, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0302, bind(&someip_service::on_message302, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0303, bind(&someip_service::on_message303, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0304, bind(&someip_service::on_message304, this, std::placeholders::_1));
   
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0401, bind(&someip_service::on_message401, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0402, bind(&someip_service::on_message402, this, std::placeholders::_1));

   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0501, bind(&someip_service::on_message501, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0502, bind(&someip_service::on_message502, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0503, bind(&someip_service::on_message503, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0504, bind(&someip_service::on_message504, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0505, bind(&someip_service::on_message505, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0506, bind(&someip_service::on_message506, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0507, bind(&someip_service::on_message507, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0508, bind(&someip_service::on_message508, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0509, bind(&someip_service::on_message509, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0510, bind(&someip_service::on_message510, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0511, bind(&someip_service::on_message511, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0512, bind(&someip_service::on_message512, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0513, bind(&someip_service::on_message513, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0514, bind(&someip_service::on_message514, this, std::placeholders::_1));
   app->register_message_handler(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID, SAMPLE_METHOD_ID0515, bind(&someip_service::on_message515, this, std::placeholders::_1));

   app->offer_service(SAMPLE_SERVICE_ID, SAMPLE_INSTANCE_ID);
   app->start();
   
   }


   
    




