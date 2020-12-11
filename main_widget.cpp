#include "main_widget.h"

using namespace std;

MainWidget::MainWidget(int screen_width, int screen_height, QWidget *parent)
    : QWidget(parent)
{
    label_size_ = (int)(screen_width * 0.3);
    word_size_ = label_size_ * 0.7;

    zplayer_ = new ZcsPlayer();
    zplayer_->start();

    label_ = new QLabel();
    label_->setAlignment(Qt::AlignCenter);
    label_->setMinimumHeight(label_size_);
    label_->setMinimumWidth(label_size_);
    QFont font("Microsoft YaHei", word_size_, QFont::Bold); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    label_->setFont(font);

//    label_->setText("红");
//    label_->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(255, 0, 255);");

    btn_a_ = new QPushButton("A");
    connect(btn_a_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);
    btn_b_ = new QPushButton("B");
    connect(btn_b_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);
    btn_c_ = new QPushButton("C");
    connect(btn_c_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);
    btn_d_ = new QPushButton("D");
    connect(btn_d_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);

    vbox_ = new QVBoxLayout();
    vbox_->addWidget(label_);

    hbox_1_ = new QHBoxLayout();
    hbox_1_->addWidget(btn_a_);
    hbox_1_->addWidget(btn_b_);

    hbox_2_ = new QHBoxLayout();
    hbox_2_->addWidget(btn_c_);
    hbox_2_->addWidget(btn_d_);

    vbox_->addLayout(hbox_1_);
    vbox_->addLayout(hbox_2_);

    this->setLayout(vbox_);
//    player_ = new QMediaPlayer(this);
//    connect(player_, SIGNAL(positionChanged(qint64)), this, SLOT(slot_position_changed(qint64)));
}

MainWidget::~MainWidget()
{
}

void MainWidget::slot_btn_clicked()
{
    QPushButton* btn = (QPushButton*)sender();
    qDebug() << btn->text();

//    label_->setText("蓝");
//    label_->setStyleSheet("color:rgb(255, 255, 0);background-color:rgb(255, 0, 0);");

//    player->setMedia(QUrl::fromLocalFile("assets:/audio/test.mp3"));
//    player_->setMedia(QUrl::fromLocalFile("assets:/audio/error_mp3_decode.wav"));
//    player_->setVolume(30);
//    int ret = player_->state();
//    qDebug() << ret << "=====================================";
//    player_->play();
//    ret = player_->state();
//    qDebug() << ret << "=====================================";
//    QMess
}

void MainWidget::slot_position_changed(qint64 pos)
{
    qDebug() << pos << "--------------";
}
