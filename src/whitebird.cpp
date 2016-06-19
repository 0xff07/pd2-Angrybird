#include "whitebird.h"

WhiteBird::WhiteBird(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{

}

void WhiteBird::behavior()
{
   b2Vec2 curVelocity = b2d_body->GetLinearVelocity();
   curVelocity.x += 10;
   curVelocity.y += 1000;
   b2d_body->SetLinearVelocity(curVelocity);
}



