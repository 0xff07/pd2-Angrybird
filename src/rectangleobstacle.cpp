#include "rectangleobstacle.h"

RectangleObstacle::RectangleObstacle (SAME_AS_BIRD):Bird (BIRD_VARIABLES)
{
    HP = 2000;
    setB2dInterface(x, y, w/2 , h/2, density, friction, restitution, angleDamp);
    setQtInterface(pixmap, w, h);
    //qt_body.setTransformOriginPoint(0, 83);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&qt_body);
}

void RectangleObstacle::behavior()
{

}

void RectangleObstacle::setB2dInterface(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp)
{


    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = false;
    bodydef.position.Set(x,y);

    bodydef.userData = this;
    b2d_body = world->CreateBody(&bodydef);


    b2PolygonShape shapeSpec;
    shapeSpec.SetAsBox(w/2, h/2);


    b2FixtureDef physicalSpec;
    physicalSpec.shape = &shapeSpec;
    physicalSpec.density = density;
    physicalSpec.friction = friction;
    physicalSpec.restitution = restitution;

    b2d_body->SetAngularDamping(angleDamp);
    b2d_body->CreateFixture(&physicalSpec);
}
