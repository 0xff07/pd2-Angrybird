#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include <QDebug>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    ~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    static QPointF b2dToQtPos(b2Vec2 b2dPoint);
    b2CircleShape setCirlularShape(double radius);
    b2PolygonShape setPolygonShape(double w, double h);
    QPointF QtPos;
    b2Vec2 b2dPos;

    QPointF getQtPos();
    b2Vec2 getB2dPos();

     void setQtInterface(QPixmap pixmap, float w, float h);
     void setB2dInterface(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp);
     //virtual void behavior();

public slots:
    void paint();
    virtual void collision();

protected:
    b2Body *b2d_body;
    QGraphicsPixmapItem qt_body;
    QSizeF Qt_size;
    b2World *world;
    static QSizeF b2d_World_Size, Qt_World_Size;
};

#endif // GAMEITEM_H
