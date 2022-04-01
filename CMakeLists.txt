cmake_minimum_required(VERSION 3.16)

project(media_reader) #Project name


#set (CMAKE_CXX_FLAGS "-g -std=c++0x")
set (VSOMEIP_NAME vsomeip3)
set (VSOMEIP_COMPAT_NAME vsomeip)

set (VSOMEIP_MAJOR_VERSION 3)
set (VSOMEIP_MINOR_VERSION 1)

find_package(PkgConfig) #finding pkg-config is a helper tool
find_package( Boost 1.71 COMPONENTS system thread log REQUIRED )

#using pkg-config to getting Gstreamer
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

#including GStreamer header files directory
include_directories(
        ${GLIB_INCLUDE_DIRS}
        ${GSTREAMER_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIR}
    	${VSOMEIP_INCLUDE_DIRS}
)

#linking GStreamer library directory
link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GSTREAMER_LIBRARY_DIRS}
)
include_directories(${VSOMEIP_INCLUDE_DIRS})
#include_directories( include )

#building target executable
add_executable(${PROJECT_NAME} media_reader.cpp usb_manager.cpp device_manager.cpp main.cpp someip_service.cpp audioDevices_manager.cpp media_manager.cpp system_facade.cpp bt_manager.cpp)

#linking Gstreamer library with target executable
target_link_libraries(media_reader gstaudio-1.0 stdc++fs stdc++ -pthread ${GSTREAMER_LIBRARIES} ${VSOMEIP_NAME} ${Boost_LIBRARIES} ${DL_LIBRARY})



