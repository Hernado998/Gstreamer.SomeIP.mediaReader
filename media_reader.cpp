#include "media_reader.h"

using namespace media;



void media_reader::handle_message (CustomData *data, GstMessage *msg) {
  GError *err;
  gchar *debug_info;

  switch (GST_MESSAGE_TYPE (msg)) {
    case GST_MESSAGE_ERROR:
      gst_message_parse_error (msg, &err, &debug_info);
      g_printerr ("Error received from element %s: %s\n", GST_OBJECT_NAME (msg->src), err->message);
      g_printerr ("Debugging information: %s\n", debug_info ? debug_info : "none");
      g_clear_error (&err);
      g_free (debug_info);
      data->terminate = TRUE;
      break;
    case GST_MESSAGE_EOS:
      g_print ("\nEnd-Of-Stream reached.\n");
      data->terminate = TRUE;
      break;
    case GST_MESSAGE_DURATION:
      /* The duration has changed, mark the current one as invalid */
      data->duration = GST_CLOCK_TIME_NONE;
      break;
    case GST_MESSAGE_STATE_CHANGED: {
      GstState old_state, new_state, pending_state;
      gst_message_parse_state_changed (msg, &old_state, &new_state, &pending_state);
      if (GST_MESSAGE_SRC (msg) == GST_OBJECT (data->playbin)) {
        g_print ("Pipeline state changed from %s to %s:\n",
            gst_element_state_get_name (old_state), gst_element_state_get_name (new_state));

        /* Remember whether we are in the PLAYING state or not */
        data->playing = (new_state == GST_STATE_PLAYING);

        if (data->playing) {
          /* We just moved to PLAYING. Check if seeking is possible */
          GstQuery *query;
          gint64 start, end;
          query = gst_query_new_seeking (GST_FORMAT_TIME);
          if (gst_element_query (data->playbin, query)) {
            gst_query_parse_seeking (query, NULL, &data->seek_enabled, &start, &end);
            if (data->seek_enabled) {
              g_print ("Seeking is ENABLED from %" GST_TIME_FORMAT " to %" GST_TIME_FORMAT "\n",
                  GST_TIME_ARGS (start), GST_TIME_ARGS (end));
            } else {
              g_print ("Seeking is DISABLED for this stream.\n");
            }
          }
          else {
            g_printerr ("Seeking query failed.");
          }
          gst_query_unref (query);
        }
      }
    } break;
    default:
      /* We should not reach here */
      g_printerr ("Unexpected message received.\n");
      break;
  }
  gst_message_unref (msg);
}

void media_reader::send_seek_event (CustomData  data)
{
  gint64 position;
  GstEvent *seek_event;
  /* Obtain the current position, needed for the seek event */
  if (!gst_element_query_position (data.playbin, GST_FORMAT_TIME, &position)) {
    g_printerr ("Unable to retrieve current position.\n");
    return;
  }
  /* Create the seek event */
  if (data.rate > 0) {
    seek_event =
        gst_event_new_seek (data.rate, GST_FORMAT_TIME,(GstSeekFlags)(GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_ACCURATE), GST_SEEK_TYPE_SET,
        position, GST_SEEK_TYPE_END, 0);
  } else {
    seek_event =
        gst_event_new_seek (data.rate, GST_FORMAT_TIME,(GstSeekFlags)(GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_ACCURATE), GST_SEEK_TYPE_SET, 0,
        GST_SEEK_TYPE_SET, position);
  }

  if (data.playbin == NULL) {
    /* If we have not done so, obtain the sink through which we will send the seek events */
    g_object_get (data.playbin, "video-sink", &data.playbin, NULL);
  }

  /* Send the event */
  gst_element_send_event (data.playbin, seek_event);

  g_print ("Current rate: %g\n", data.rate);
}

void media_reader::StartPlayingMedia(){
    /* Start playing */
    
    ret = gst_element_set_state (data.playbin, GST_STATE_PLAYING);
    double volume;
    volume = gst_stream_volume_get_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC);
    gst_stream_volume_set_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC,volume-0.6);
    if (ret == GST_STATE_CHANGE_FAILURE) {
      g_printerr ("Unable to set the pipeline to the playing state.\n");
      gst_object_unref (data.playbin);
      
    }
    MediaReader();
}

int media_reader::Initialize(string path){
  if(dispo){
    cout<<"Im dispo"<<endl;
    dispo=false;
    data.playing = FALSE;
    data.terminate = FALSE;
    data.seek_enabled = FALSE;
    data.seek_done = FALSE;
    data.duration = GST_CLOCK_TIME_NONE;
      /* Initialize GStreamer */
    gst_init (NULL,NULL);
    /* Create the elements */
    data.playbin = gst_element_factory_make ("playbin", "playbin");

    if (!data.playbin) {
      g_printerr ("Not all elements could be created.\n");
      return -1;
    }
    /* Set the URI to play */ 
    const char *word="file:///";
    const char *word2=path.c_str();
    addTohistory(word2);
    char *p = new char[strlen(word)+strlen(word2)+1];
    strcpy(p,word);
    strcat(p,word2);
    cout<<"Initializing ..."<<endl;
    cout<<p<<endl;
    g_object_set (data.playbin, "uri", p, NULL);
    StartPlayingMedia();
  }
  else{
    cout<<"Im not dispo"<<endl;
    data.terminate=true;
    dispo=true; 
  }
  return 0; 
}

void media_reader::MediaReader(){
    /* Listen to the bus */
  bus = gst_element_get_bus (data.playbin);
  do {
    msg = gst_bus_timed_pop_filtered (bus, 100 * GST_MSECOND,(GstMessageType)(GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS | GST_MESSAGE_DURATION));
    /* Parse message */
    if (msg != NULL) {
      handle_message (&data, msg);
    } else {
      /* We got no message, this means the timeout expired */
      if (data.playing) {
        gint64 current = -1;
        /* Query the current position of the stream */
        if (!gst_element_query_position (data.playbin, GST_FORMAT_TIME, &current)) {
          g_printerr ("Could not query current position.\n");
        }
        /* If we didn't know it yet, query the stream duration */
        if (!GST_CLOCK_TIME_IS_VALID (data.duration)) {
          if (!gst_element_query_duration (data.playbin, GST_FORMAT_TIME, &data.duration)) {
            g_printerr ("Could not query current duration.\n");
          }
        } 
     
      }
    }
  } while (!data.terminate);

  /* Free resources */
  gst_object_unref (bus);
  gst_element_set_state (data.playbin, GST_STATE_NULL);
  gst_object_unref (data.playbin);
  dispo=true;
}
void media_reader::volume_down(){
  double volume;
  volume = gst_stream_volume_get_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC);
	gst_stream_volume_set_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC,volume-0.1);
  cout<<"volume down"<<endl;
}
void media_reader::volume_up(){
  double volume;
  volume = gst_stream_volume_get_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC);
	gst_stream_volume_set_volume(GST_STREAM_VOLUME(data.playbin),GST_STREAM_VOLUME_FORMAT_CUBIC,volume+0.1);
  cout<<"volume up"<<endl;
}

void media_reader::playing_speed_up(){
  data.rate *= 2.0;send_seek_event (data);
}
void media_reader::playing_speed_down(){
  data.rate /= 2.0;send_seek_event (data);
}
void media_reader::reverse_playing_direction(){
  data.rate *= -1.0;send_seek_event (data);
}
void media_reader::play_pause(){
  data.playing = !data.playing;
	gst_element_set_state (data.playbin,data.playing ? GST_STATE_PLAYING : GST_STATE_PAUSED);
	g_print ("Setting state to %s\n", data.playing ? "PLAYING" : "PAUSE");
}
gint64 media_reader::get_time(){
  gint64 current = -1;
  gst_element_query_position (data.playbin, GST_FORMAT_TIME, &current);
  printf("Position %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r\n",GST_TIME_ARGS (current), GST_TIME_ARGS (data.duration));
  return current;
}
gint64 media_reader::getMediaLength(){
  return data.duration;
}
void media_reader::shutdown(){
  data.terminate=true;
  dispo=true;
}

void media_reader::addTohistory(string myLine){
  ofstream outfile ("historylist.txt", ios_base::app);
    // current date/time based on current system
  time_t now = time(0);
   // convert now to string form
  char* dt = ctime(&now);
  outfile <<myLine<< endl;
}




