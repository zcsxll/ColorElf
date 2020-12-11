QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    main_widget.cpp \
    zcs_player.cpp \
    zcs_semaphore.cpp

HEADERS += \
    main_widget.h \
    zcs_player.h \
    zcs_semaphore.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

android {
    audio.files += audio/*.mp3
    audio.files += audio/*.wav
    audio.path = /assets/audio
    INSTALLS += audio
}
