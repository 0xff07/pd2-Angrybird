#include "whitebird.h"

WhiteBird::WhiteBird(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{

}

void WhiteBird::behavior()
{
   b2Vec2 curVelocity = b2d_body->GetLinearVelocity();
   curVelocity.x *= 3;
   curVelocity.y *= 3;
   b2d_body->SetLinearVelocity(curVelocity);
}



