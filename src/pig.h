#ifndef PIG_H
#define PIG_H

#include "bird.h"

class Pig : public Bird
{
public:
    Pig(float x, float y,
         float w, float h, float density, float friction, float restitution, float angleDamp,
         QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void behavior();
private:
    int HP;
};

#endif // PIG_H
