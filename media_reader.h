#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <experimental/filesystem>
#include <gstreamer-1.0/gst/gst.h>
#include <gstreamer-1.0/gst/audio/streamvolume.h>
//#include "someip_service.h"

#define BITS 8
using namespace std;

namespace fs = std::experimental::filesystem;
#ifndef MEDIA_READER_H
#define MEDIA_READER_H
/* Structure to contain all our information, so we can pass it around */
namespace media{
  typedef struct _CustomData  {
    GstElement *playbin;  /* Our one and only element */
    gboolean playing;      /* Are we in the PLAYING state? */
    gboolean terminate;    /* Should we terminate execution? */
    gboolean seek_enabled; /* Is seeking enabled for this media? */
    gboolean seek_done;    /* Have we performed the seek already? */
    gint64 duration;		/* How long does this media last, in nanoseconds */
    gdouble rate;       /* Current playback rate (can be negative) */
    gdouble volume;      /* volume of the media */
  } CustomData;
/*************************************************************************
* media_reader class is the class responsible of reading a media and of controling 
* the media status
***************************************************************************/
  class media_reader{
      public:
          CustomData data;
          GstBus *bus;
          GstMessage *msg;
          GstStateChangeReturn ret;
          
          void handle_message (CustomData *data, GstMessage *msg);
          void send_seek_event (CustomData  data); // update the seeking pointer
          
          int Initialize(string path); // prepare the flow (media) that need to be played
          void StartPlayingMedia(); // start playing the media (use this function after the initialize function)
          void MediaReader(); // activate media seeking 
          gint64 get_time(); // return the current position of the media (in nanoSeconds)
          gint64 getMediaLength(); // return the media length (in nanoSeconds)
          void playing_speed_up(); // decrease playing speed
          void playing_speed_down(); // increase palying speed
          void reverse_playing_direction(); // reverse playing direction
          void play_pause(); // change to palying/paused states
          void volume_down(); // decrease volume -0.1
          void volume_up(); // increase volume +0.1
          void shutdown(); // shutdown the current media
          void addTohistory(string mp3); // add media to the history medias file

          bool dispo=true; // dispo=true ==> the media reader is free
  };
}
#endif
