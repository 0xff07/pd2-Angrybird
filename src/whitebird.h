#ifndef WHITEBIRD_H
#define WHITEBIRD_H

#include "bird.h"

class WhiteBird : public Bird
{
public:
    WhiteBird(SAME_AS_BIRD);
    void behavior();
};

#endif // WHITEBIRD_H
