#include "zcs_player.h"

ZcsPlayer::ZcsPlayer()
{

}

void ZcsPlayer::run()
{
    while(true)
    {
        qDebug() << 11;
        QAudioFormat format;
        format.setSampleRate(16000);
        format.setChannelCount(1);
        format.setSampleSize(16);
        format.setCodec("audio/pcm");
        format.setByteOrder(QAudioFormat::LittleEndian);
        format.setSampleType(QAudioFormat::SignedInt);

        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
        qDebug() << info.supportedCodecs();
        if (!info.isFormatSupported(format))
        {
            qWarning() << "Raw audio format not supported by backend, cannot play audio.";
            break;
        }

        QAudioOutput *audio_ = new QAudioOutput(format, 0);
        audio_->reset();
        QFile file;
        file.setFileName("assets:/audio/error_mp3_decode.wav");
        file.open(QIODevice::ReadOnly);
        qDebug() << file.isOpen() << "iiiiiiiiiiiiiiiiiiii";
        audio_->start(&file);

        sleep(10);
    }
}
