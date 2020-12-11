#include "main_widget.h"

#include <QApplication>
#include <QScreen>
#include <QGuiApplication>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry() ;
//    int screen_width = mm.width();
//    int screen_height = mm.height();
//    qDebug() << screen_width << screen_height;
//    string size = to_string(screen_height) + " " + to_string(screen_width);
//    label_->setText(size.c_str());
    MainWidget w(mm.width(), mm.height());
    w.show();

//    QAudioFormat format;
//    format.setSampleRate(16000);
//    format.setChannelCount(1);
//    format.setSampleSize(16);
//    format.setCodec("audio/pcm");
//    format.setByteOrder(QAudioFormat::LittleEndian);
//    format.setSampleType(QAudioFormat::SignedInt);

//    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
//    qDebug() << info.supportedCodecs();
//    if (!info.isFormatSupported(format))
//    {
//        qWarning() << "Raw audio format not supported by backend, cannot play audio.";
//        return -1;
//    }

//    QAudioOutput *audio_ = new QAudioOutput(format, 0);
//    audio_->reset();
//    QFile file;
//    file.setFileName("assets:/audio/error_mp3_decode.wav");
//    file.open(QIODevice::ReadOnly);
//    qDebug() << file.isOpen() << "iiiiiiiiiiiiiiiiiiii";
//    audio_->start(&file);

    return a.exec();
}
