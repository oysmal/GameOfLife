#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eventinterface.h"
#include "grid.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QList>
#include <QPoint>
#include "gameoflife.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public EventInterface, public Subscriber
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadGridIntoView();
    void render();
    QPoint scalePosition(int i, int j);
    void notify(std::shared_ptr<Event> e);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene;
    Gameoflife game;

private slots:
    void startGame();
    void iterateGame();
    void stopGame();
};

#endif // MAINWINDOW_H
