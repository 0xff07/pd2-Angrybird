#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "bird.h"
#include "QDebug"

class YellowBird : public Bird
{
    //Q_OBJECT

public:
    YellowBird(SAME_AS_BIRD);
    void behavior();

};

#endif // YELLOWBIRD_H
