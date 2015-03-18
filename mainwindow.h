#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadGridIntoView();
    void render();
    QPoint scalePosition(int i, int j);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene;
    //Gameoflife game;

private slots:
    void startGame();
    void iterateGame();
    void stopGame();
};

#endif // MAINWINDOW_H
