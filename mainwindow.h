#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eventinterface.h"
#include "grid.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public EventInterface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadGridIntoView();
    void render();

private:
    Ui::MainWindow *ui;
    Grid *grid;
    QGraphicsScene *scene;
    QList<QGraphicsRectItem*> points;
    QGraphicsView graphicsView;

private slots:
    void sendEventTest();
};

#endif // MAINWINDOW_H
