#include <iomanip>
#include <iostream>
#include <sstream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <vsomeip/vsomeip.hpp>
//#include "Subject.h"
//#include "Observer.h"
//#include "ids.h"
#include "system_facade.h"
#define BITS 8
using namespace std;
using namespace facade;
#ifndef SOMEIP_SERVICE_H
#define SOMEIP_SERVICE_H
/*************************************************************************
* someip_service class is the class responsible of managing the medias in
* the usb stick and it also interacts with cache and playlists
***************************************************************************/
    class someip_service{
        public:
            std::shared_ptr<vsomeip::application> app;
            
            system_facade SF;
            std::string detectedDevice;
  
            void Init(); //Initialize the service by registring message handlers and offering a service

            //media_manager methods    
            void on_message001(const std::shared_ptr<vsomeip::message> &_request);
            void on_message002(const std::shared_ptr<vsomeip::message> &_request);
            void on_message003(const std::shared_ptr<vsomeip::message> &_request);
            void on_message004(const std::shared_ptr<vsomeip::message> &_request);
            void on_message005(const std::shared_ptr<vsomeip::message> &_request);
            void on_message006(const std::shared_ptr<vsomeip::message> &_request);
            void on_message007(const std::shared_ptr<vsomeip::message> &_request);
            void on_message008(const std::shared_ptr<vsomeip::message> &_request);

            //media_reader methods
            void on_message101(const std::shared_ptr<vsomeip::message> &_request);
            void on_message102(const std::shared_ptr<vsomeip::message> &_request);
            void on_message103(const std::shared_ptr<vsomeip::message> &_request);
            void on_message104(const std::shared_ptr<vsomeip::message> &_request);
            void on_message105(const std::shared_ptr<vsomeip::message> &_request);
            void on_message106(const std::shared_ptr<vsomeip::message> &_request);
            void on_message107(const std::shared_ptr<vsomeip::message> &_request);
            void on_message108(const std::shared_ptr<vsomeip::message> &_request);
            void on_message109(const std::shared_ptr<vsomeip::message> &_request);
            void on_message110(const std::shared_ptr<vsomeip::message> &_request);
            void on_message111(const std::shared_ptr<vsomeip::message> &_request);

            //device_manager methods
            void on_message201(const std::shared_ptr<vsomeip::message> &_request);

            //usb_manager methods
            void on_message301(const std::shared_ptr<vsomeip::message> &_request);
            void on_message302(const std::shared_ptr<vsomeip::message> &_request);
            void on_message303(const std::shared_ptr<vsomeip::message> &_request);
            void on_message304(const std::shared_ptr<vsomeip::message> &_request);
            
            //audioDevices_manager methods
            void on_message401(const std::shared_ptr<vsomeip::message> &_request);
            void on_message402(const std::shared_ptr<vsomeip::message> &_request);

            //bt_manager methods
            void on_message501(const std::shared_ptr<vsomeip::message> &_request);
            void on_message502(const std::shared_ptr<vsomeip::message> &_request);
            void on_message503(const std::shared_ptr<vsomeip::message> &_request);
            void on_message504(const std::shared_ptr<vsomeip::message> &_request);
            void on_message505(const std::shared_ptr<vsomeip::message> &_request);
            void on_message506(const std::shared_ptr<vsomeip::message> &_request);
            void on_message507(const std::shared_ptr<vsomeip::message> &_request);
            void on_message508(const std::shared_ptr<vsomeip::message> &_request);
            void on_message509(const std::shared_ptr<vsomeip::message> &_request);
            void on_message510(const std::shared_ptr<vsomeip::message> &_request);
            void on_message511(const std::shared_ptr<vsomeip::message> &_request);
            void on_message512(const std::shared_ptr<vsomeip::message> &_request);
            void on_message513(const std::shared_ptr<vsomeip::message> &_request);
            void on_message514(const std::shared_ptr<vsomeip::message> &_request);
            void on_message515(const std::shared_ptr<vsomeip::message> &_request);

    };
#endif