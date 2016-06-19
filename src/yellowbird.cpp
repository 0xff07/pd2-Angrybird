#include "yellowbird.h"

YellowBird::YellowBird(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{


}


void YellowBird::behavior()
{
    b2Vec2 curVelocity = b2d_body->GetLinearVelocity();
    curVelocity.y = -1*100;
    curVelocity.x = 0;
    b2d_body->SetLinearVelocity(curVelocity);
}

