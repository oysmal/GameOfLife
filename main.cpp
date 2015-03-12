#include "mainwindow.h"
#include <QApplication>
#include "eventtest.h"
#include "eventhandler.h"

int main(int argc, char *argv[])
{

    EventTest et;
    EventHandler::getInstance().notify_subscribers();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
