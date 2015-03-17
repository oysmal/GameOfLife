#include "mainwindow.h"
#include <QApplication>
#include "eventhandler.h"

int main(int argc, char *argv[])
{

    EventHandler::getInstance().notify_subscribers();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
