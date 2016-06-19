#include "bird.h"

Bird::Bird(float x, float y,
           float w, float h, float density, float friction, float restitution, float angleDamp,
           QTimer *timer, QPixmap pixmap,
           b2World *world, QGraphicsScene *scene):GameItem(world)
{
    shooted = 0;
    skillUsed = 0;
    setB2dInterface(x, y, w , h, density, friction, restitution, angleDamp);
    setQtInterface(pixmap, w, h);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&qt_body);



}


void Bird::setQtInterface(QPixmap pixmap, float w, float h)
{
    qt_body.setPixmap(pixmap);
#ifdef SQUARE
  qt_body.setTransformOriginPoint(qt_body.boundingRect().width()/2,qt_body.boundingRect().height()/2);
#else
    qt_body.setTransformOriginPoint(qt_body.boundingRect().width()/2,qt_body.boundingRect().height()/2);
#endif
    Qt_size = QSize(w/2, h/2);
}



void Bird::setB2dInterface(float x, float y, float w, float h, float density, float friction, float restitution, float angleDamp)
{
    this->density = density;
    this->friction = friction;
    this->restitution = restitution;
    this->angleDamp = angleDamp;
    this->w = w;
    this->h = h;
    this->radius = (w + h)/4;
    this->velocity = b2Vec2(0, 0);

    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);

    bodydef.userData = this;
    b2d_body = world->CreateBody(&bodydef);


#ifdef SQUARE
    b2PolygonShape shapeSpec = setPolygonShape(w, h);
    shapeSpec.SetAsBox(w/2, h/2);
#else
    b2CircleShape shapeSpec = setCirlularShape(radius);
#endif

    b2FixtureDef physicalSpec;
    physicalSpec.shape = &shapeSpec;
    physicalSpec.density = density;
    physicalSpec.friction = friction;
    physicalSpec.restitution = restitution;

    b2d_body->SetAngularDamping(angleDamp);
    b2d_body->CreateFixture(&physicalSpec);
}

void Bird::behavior()
{

}

void Bird::collision()
{
 qDebug() << "from bird";
}



void Bird::setLinearVelocity(b2Vec2 velocity)
{
    this->velocity = b2Vec2(velocity.x, velocity.y);
    b2d_body->SetLinearVelocity(this->velocity);

    qDebug() << "setLinearVelocity is called !";
    qDebug() << "The received velocity is:" << this->velocity.x << this->velocity.y;
    qDebug() << "the velocity in b2d is:" << getVelocity().x << " " << getVelocity().y;
}



void Bird::setGravityEffect(float parameter)
{
    b2d_body->SetGravityScale(parameter);
}



b2Vec2 Bird::getVelocity() const
{
    return b2d_body->GetLinearVelocity();
}

int Bird::currentBirdNo(0);








/*
b2FixtureDef Bird::setPhysicalSpecDef(b2CircleShape *shapeSpect)
{
    b2FixtureDef physicalSpec;
    physicalSpec.shape = shapeSpect;
    physicalSpec.density = density;
    physicalSpec.friction = friction;
    physicalSpec.restitution = restitution;
    return physicalSpec;
}
*/


/*
void Bird::setPhysicalProperty(float density, float friction, float restitution, float radius)
{
    this->density = density;
    this->friction = friction;
    this->restitution = restitution;
    this->radius = radius;
}
*/
\

