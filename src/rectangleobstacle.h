#ifndef RECTANGLEOBSTACLE_H
#define RECTANGLEOBSTACLE_H


//#define SQUARE true
#include "bird.h"


class RectangleObstacle : public Bird
{
public:
    RectangleObstacle(SAME_AS_BIRD) ;

    void behavior();

    void setB2dInterface(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp);

private:
    int HP;
};

#endif // RECTANGLEOBSTACLE_H
