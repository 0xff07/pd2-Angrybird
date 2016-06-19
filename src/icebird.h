#ifndef ICEBIRD_H
#define ICEBIRD_H

#include "bird.h"

class IceBird : public Bird
{
public:
    IceBird(SAME_AS_BIRD);
    void behavior();
};

#endif // ICEBIRD_H
