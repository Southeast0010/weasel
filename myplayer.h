#ifndef MYPLAYER
#define MYPLAYER
#include <QMediaPlayer>

class myPlayer{
private:
    static myPlayer* instance;
    QMediaPlayer player;
    myPlayer(){}
public:
    static myPlayer* getInstance(){
        if(!instance){
            instance = new myPlayer;
        }
        return instance;
    }
    void play(QString const& address);
    void pause();
    void stop();
};
#endif // MYPLAYER

