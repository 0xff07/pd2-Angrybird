#include "gameitem.h"

#include <iostream>

GameItem::GameItem(b2World *world):
    b2d_body(NULL),world(world)
{
}

GameItem::~GameItem()
{
    world->DestroyBody(b2d_body);
}

QSizeF GameItem::Qt_World_Size = QSizeF();
QSizeF GameItem::b2d_World_Size = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    b2d_World_Size = worldsize;
    Qt_World_Size = windowsize;
}

QPointF GameItem::b2dToQtPos(b2Vec2 b2dPoint)
{
    float x = b2dPoint.x;
    float y = b2dPoint.y;
    QPointF mappedPoint;
    mappedPoint.setX(((x) * Qt_World_Size.width())/b2d_World_Size.width());
    mappedPoint.setY((1.0f - (y)/b2d_World_Size.height()) * Qt_World_Size.height());
    return mappedPoint;
}

QPointF GameItem::getQtPos()
{
    return qt_body.pos();
}

b2Vec2 GameItem::getB2dPos()
{
    return b2d_body->GetPosition();
}

void GameItem::paint()
{
    b2Vec2 pos = b2d_body->GetPosition();
    b2Vec2 b2d_size = b2Vec2(Qt_size.width()/8, Qt_size.height()/8);
    //std::cout << g_body->GetAngle() << std::endl;
    QPointF mappedPoint;


    mappedPoint.setX(((pos.x-b2d_size.x/2) * Qt_World_Size.width())/b2d_World_Size.width());
    mappedPoint.setY((1.0f - (pos.y+b2d_size.y/2)/b2d_World_Size.height()) * Qt_World_Size.height());


   //qDebug() << mappedPoint;


    qt_body.setPos(mappedPoint);
    qt_body.resetTransform();
    qt_body.setRotation(-(b2d_body->GetAngle()*180/3.14159));
}

void GameItem::collision()
{

}

b2CircleShape GameItem::setCirlularShape(double radius)
{
    b2CircleShape shapeSpect;
    shapeSpect.m_radius = radius;
    return shapeSpect;
}

b2PolygonShape GameItem::setPolygonShape(double w, double h)
{
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w,h);
    return bodyBox;
}
