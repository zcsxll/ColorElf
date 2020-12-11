#include "zcs_player.h"

//void ZcsPlayer::slot_audio_state(QAudio::State state)
//{
//    qDebug() << state;
//}

ZcsPlayer::ZcsPlayer() : audio_(NULL)
{
    format_.setSampleRate(16000);
    format_.setChannelCount(1);
    format_.setSampleSize(16);
    format_.setCodec("audio/pcm");
    format_.setByteOrder(QAudioFormat::LittleEndian);
    format_.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
//    qDebug() << info.supportedCodecs();
    if (!info.isFormatSupported(format_))
    {
        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
        return;
    }

    audio_ = new QAudioOutput(format_, 0);
//    connect(audio_, SIGNAL(stateChanged(QAudio::State)), this, SLOT(slot_audio_state(QAudio::State)));
//    audio_state_ = 0;
}

void ZcsPlayer::run()
{
    QFile file;
    string wave_path;
    int flag;
    while(true)
    {
        pair<string, int> cmd = zsem_.acquire();

        if(audio_->state() != QAudio::State::IdleState && audio_->state() != QAudio::State::StoppedState)
        {
            qDebug() << "audio is running";
            if(cmd.second == 0)
            {
                continue;
            }
            qDebug() << "force stop";
            audio_->stop();
        }

        audio_->reset();
        file.close();
//        file.setFileName("assets:/audio/error_mp3_decode.wav");
        file.setFileName(cmd.first.c_str());
        file.open(QIODevice::ReadOnly);
        if(!file.isOpen())
        {
            qWarning() << "cannot open file";
            continue;
        }
        audio_->start(&file);
    }
}

int ZcsPlayer::play(const string &wav, bool force_stop)
{
    zsem_.release(wav, int(force_stop));
    return 0;
}
