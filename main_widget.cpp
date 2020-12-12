#include "main_widget.h"

using namespace std;

void MainWidget::slot_btn_clicked(int id)
{
    qDebug() << " " << id;
    if(answer_btn_id_ == id)
    {
//        zplayer_->play("assets:/audio_wav/correct.wav", true);
//        sleep(2);
        this->update_qa();
    }
    else
    {
        zplayer_->play("assets:/audio_wav/wrong.wav", false);
    }
//    zplayer_->play("assets:/audio_wav/correct.wav", true);

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

MainWidget::MainWidget(int screen_width, int screen_height, QWidget *parent)
    : QWidget(parent)
{
    label_size_ = (int)(screen_width * 0.3);
    word_size_ = label_size_ * 0.7;

    zplayer_ = new ZcsPlayer();
    zplayer_->start();

    zcolor_ = new ZcsColor();

    label_ = new QLabel();
    label_->setAlignment(Qt::AlignCenter);
    label_->setMinimumHeight(label_size_);
    label_->setMinimumWidth(label_size_);
    QFont font("Microsoft YaHei", word_size_, QFont::Bold); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    label_->setFont(font);

    btn_a_ = new QPushButton("A");
    connect(btn_a_, &QPushButton::clicked, [=] { slot_btn_clicked(0); });
//    connect(btn_a_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);
    btn_b_ = new QPushButton("B");
    connect(btn_b_, &QPushButton::clicked, [=] { slot_btn_clicked(1); });
    btn_c_ = new QPushButton("C");
    connect(btn_c_, &QPushButton::clicked, [=] { slot_btn_clicked(2); });
    btn_d_ = new QPushButton("D");
    connect(btn_d_, &QPushButton::clicked, [=] { slot_btn_clicked(3); });

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

    int height = btn_a_->width() * 0.5;
    btn_a_->setMinimumHeight(height);
    btn_b_->setMinimumHeight(height);
    btn_c_->setMinimumHeight(height);
    btn_d_->setMinimumHeight(height);

    this->setLayout(vbox_);
//    player_ = new QMediaPlayer(this);
//    connect(player_, SIGNAL(positionChanged(qint64)), this, SLOT(slot_position_changed(qint64)));

    this->update_qa();

//    QColor b_color = btn_a_->palette().color(QPalette::Background);
//    qDebug() << b_color.red() << " " << b_color.green() << " " << b_color.blue();
}

MainWidget::~MainWidget()
{
}

void MainWidget::update_qa()
{
    QuestionColorPlan qcp = zcolor_->get_question_plan();
    AnswerColorPlan acp = zcolor_->get_answer_plan(&qcp);

    zplayer_->play(qcp.question_audio(), true);

    label_->setText(qcp.w_name_.c_str());
    label_->setStyleSheet(qcp.style_string_.c_str());

    btn_a_->setText(acp.v_c_[0].c_str());
    if(acp.v_c_[0] == "") btn_a_->setStyleSheet(acp.v_style_[0].c_str());
    else btn_a_->setStyleSheet("background-color: rgb(243, 243, 243);");

    btn_b_->setText(acp.v_c_[1].c_str());
    if(acp.v_c_[1] == "") btn_b_->setStyleSheet(acp.v_style_[1].c_str());
    else btn_b_->setStyleSheet("background-color: rgb(243, 243, 243);");

    btn_c_->setText(acp.v_c_[2].c_str());
    if(acp.v_c_[2] == "") btn_c_->setStyleSheet(acp.v_style_[2].c_str());
    else btn_c_->setStyleSheet("background-color: rgb(243, 243, 243);");

    btn_d_->setText(acp.v_c_[3].c_str());
    if(acp.v_c_[3] == "") btn_d_->setStyleSheet(acp.v_style_[3].c_str());
    else btn_d_->setStyleSheet("background-color: rgb(243, 243, 243);");

    qDebug() << "question id: " << qcp.q_id_ <<" answer id: " << acp.aid_;

//    btn_a_->setStyleSheet("background-color: rgb(170, 0, 255);");
    answer_btn_id_ = acp.aid_;
}
