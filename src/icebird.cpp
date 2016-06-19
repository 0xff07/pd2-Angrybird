#include "icebird.h"

IceBird::IceBird(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{

}

void IceBird::behavior()
{

    b2CircleShape shapeSpec = setCirlularShape(radius * 2);
    b2FixtureDef physicalSpec;
    physicalSpec.shape = &shapeSpec;
    physicalSpec.density = density * 2;
    physicalSpec.friction = friction * 2;
    physicalSpec.restitution = restitution * 2;

    b2d_body->SetAngularDamping(angleDamp);
    b2d_body->CreateFixture(&physicalSpec);

}
