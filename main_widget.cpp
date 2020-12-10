#include "main_widget.h"

using namespace std;

MainWidget::MainWidget(int screen_width, int screen_height, QWidget *parent)
    : QWidget(parent)
{
    label_size_ = (int)(screen_width * 0.3);
    word_size_ = label_size_ * 0.7;

    btn_ = new QPushButton("枚举设备");
    connect(btn_, &QPushButton::clicked, this, &MainWidget::slot_btn_clicked);

    label_ = new QLabel();
    label_->setAlignment(Qt::AlignCenter);
    label_->setMinimumHeight(label_size_);
    label_->setMinimumWidth(label_size_);
    QFont font("Microsoft YaHei", word_size_, QFont::Bold); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    label_->setFont(font);

    label_->setText("红");
    label_->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(255, 0, 255);");

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(btn_);
    vbox->addWidget(label_);
//    label_->

    this->setLayout(vbox);
}

MainWidget::~MainWidget()
{
}

void MainWidget::slot_btn_clicked()
{
    label_->setText("蓝");
    label_->setStyleSheet("color:rgb(255, 255, 0);background-color:rgb(255, 0, 0);");
}
