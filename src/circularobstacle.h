#ifndef CIRCULAROBSTACLE_H
#define CIRCULAROBSTACLE_H

#include "bird.h"

class CircularObstacle : public Bird
{
public:
    CircularObstacle(SAME_AS_BIRD);
    void behavior();
private:
    int HP;
};

#endif // CIRCULAROBSTACLE_H
