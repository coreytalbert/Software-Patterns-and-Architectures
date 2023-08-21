#ifndef ADAPTER_H
#define ADAPTER_H
#include <iostream>
#include "iPlayable.hpp"
#include "Mp4Player.hpp"
#include "WmvPlayer.hpp"

using namespace std;

class Adapter:public iPlayable { //extends iPLayable
  public:
  //type - player type
  //name - audio filename
    void play(string type, string name) { // factory
        if(type == "mp4") {
            mp4player->playMp4(name); // defined in Mp4Player
        } else if(type == "wmv") {
            wmvPlayer->playWmv(name); // defined in WmvPlayer
        }
    }
    Mp4Player *mp4player = new Mp4Player(); // Player objects at class level 
    WmvPlayer *wmvPlayer = new WmvPlayer();
};

#endif