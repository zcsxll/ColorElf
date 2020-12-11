#ifndef ZCSPLAYER_H
#define ZCSPLAYER_H

#include <QThread>
#include <QAudioOutput>
#include <QFile>
//#include <QSemaphore>
#include <QDebug>

#include <string>

#include "zcs_semaphore.h"

using namespace std;

class ZcsPlayer : public QThread
{
    Q_OBJECT

private:
    QAudioFormat format_;
    QAudioOutput *audio_;
//    QAudio::State audio_state_;
    ZcsSemaphore zsem_;

private slots:
//    void slot_audio_state(QAudio::State);

public:
    ZcsPlayer();

    void run() override;
    int play(const string &wav, bool force_stop = false);
};

#endif // ZCSPLAYER_H
