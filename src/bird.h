#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

#define SAME_AS_BIRD float x,float y,float w,float h,float density,float friction,float restitution,float angleDamp, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene
#define BIRD_VARIABLES x, y, w, h, density, friction, restitution, angleDamp, timer, pixmap, world, scene
#define BIRD_SIZE 4
#define BIRD_DENSITY 40

class Bird : public GameItem
{
public:
    Bird(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp,
         QTimer *timer, QPixmap pixmap,
         b2World *world, QGraphicsScene *scene);

    void setLinearVelocity(b2Vec2 velocity);
    void setGravityEffect(float parameter);
    b2Vec2 getVelocity() const;
    static int currentBirdNo;

    void setQtInterface(QPixmap pixmap, float w, float h);
    void setB2dInterface(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp);

    virtual void behavior();
    int shooted;
    int skillUsed;



//private:
    float density;
    float friction;
    float restitution;
    float angleDamp;
    float radius;
    float w;
    float h;
    b2Vec2 velocity;

};

#endif // BIRD_H
