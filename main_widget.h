#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    int label_size_;
    int word_size_;

    QPushButton *btn_;
    QLabel *label_;

private slots:
    void slot_btn_clicked();

public:
    MainWidget(int screen_width, int screen_height, QWidget *parent = nullptr);
    ~MainWidget();
};
#endif // MAINWIDGET_H
