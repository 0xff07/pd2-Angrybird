#ifndef PIGWEAK_H
#define PIGWEAK_H

#include "bird.h"

class PigWeak : public Bird
{
public:
    PigWeak(SAME_AS_BIRD);
    void behavior();
    void collision();
    int HP;
};

#endif // PIGWEAK_H
