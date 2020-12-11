#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
//#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QDebug>

#include "zcs_player.h"
#include "zcs_color.h"

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    int label_size_;
    int word_size_;

    ZcsPlayer *zplayer_;
    ZcsColor *zcolor_;

    QLabel *label_;
    QPushButton *btn_a_;
    QPushButton *btn_b_;
    QPushButton *btn_c_;
    QPushButton *btn_d_;

    QVBoxLayout *vbox_;
    QHBoxLayout *hbox_1_;
    QHBoxLayout *hbox_2_;

private slots:
    void slot_btn_clicked();
//    void slot_position_changed(qint64 pos);

public:
    MainWidget(int screen_width, int screen_height, QWidget *parent = nullptr);
    ~MainWidget();
};
#endif // MAINWIDGET_H
