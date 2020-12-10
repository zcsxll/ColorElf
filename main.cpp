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
    return a.exec();
}
