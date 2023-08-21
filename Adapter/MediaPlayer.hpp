#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H
#include <iostream>
#include "iPlayable.hpp"
#include "WmvPlayer.hpp"
#include "Mp4Player.hpp"

using namespace std;

class MediaPlayer:public iPlayable { //extends iPlayable
  public:
    void play(string type, string name) {
        if(type == "mp3") {
            cout << "Playing mp3 file: " << name << endl;
        } else if(type == "cd") {
            cout << "Playing CD: " << name << endl;
        } else if(type == "mp4") {
            mp4_player->playMp4(name); // adapter eliminated
        } else if(type == "wmv") {
            wmv_player->playWmv(name); // adapter eliminated
        } else {
            cout << "Invalid media. Format not supported." << endl;
        }
    }
    WmvPlayer * wmv_player= new WmvPlayer();
    Mp4Player * mp4_player= new Mp4Player();
    //Adapter *adapter = new Adapter();
};

#endif