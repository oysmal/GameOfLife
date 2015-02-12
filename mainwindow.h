#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eventinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public EventInterface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void sendEventTest();
};

#endif // MAINWINDOW_H
