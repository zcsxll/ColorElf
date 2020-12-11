#ifndef ZCSPLAYER_H
#define ZCSPLAYER_H

#include <QThread>
#include <QAudioOutput>
#include <QFile>
#include <QDebug>

class ZcsPlayer : public QThread
{
public:
    ZcsPlayer();

    void run() override;
};

#endif // ZCSPLAYER_H
