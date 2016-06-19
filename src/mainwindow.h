#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>
#include <QMouseEvent>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include "circularobstacle.h"
#include "rectangleobstacle.h"
#include "pig.h"
#include "yellowbird.h"
#include "whitebird.h"
#include "icebird.h"
#include "contectlistener.h"

#define WORLD_WIDTH 160
#define WORLD_HEIGHT 100
#define FLOOR_HEIGHT 14

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 800

#define PIXEL_PER_M 8



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void setGameScene();

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<Bird*> birdList;
    QList<Bird*> temp;
    QList<RectangleObstacle*> rectList;
    QList<Pig*>pigList;
    QTimer timer;
    int mousePressState;
    int maxBirdNum;
    QList<Bird*>::iterator focus;
    ContectListener* detecter;

};

#endif // MAINWINDOW_H
