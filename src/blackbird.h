#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include "bird.h"

class BlackBird : public Bird
{
public:
    BlackBird(SAME_AS_BIRD);
    virtual void behavior();
};

#endif // BLACKBIRD_H
