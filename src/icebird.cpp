#include "icebird.h"

IceBird::IceBird(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{

}

void IceBird::behavior()
{

    b2Vec2 curVelocity = b2d_body->GetLinearVelocity();
    curVelocity.y = -1*100;
    b2d_body->SetLinearVelocity(curVelocity);

}
