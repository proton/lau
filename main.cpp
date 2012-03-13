#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QTextCodec"

int main(int argc, char *argv[])
{
    QTextCodec *RusCodec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForTr(RusCodec);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
