#include "myplayer.h"

myPlayer* myPlayer::instance = NULL;

void myPlayer::play(QString const& address){
    getInstance()->player.stop();
    player.setMedia(QUrl::fromLocalFile(address));
    player.setVolume(50);
    player.play();
}

void myPlayer::pause(){
    getInstance()->player.pause();
}

void myPlayer::stop(){
    getInstance()->player.stop();
}
