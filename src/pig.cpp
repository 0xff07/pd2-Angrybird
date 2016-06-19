#include "pig.h"



Pig::Pig(float x, float y,
         float w, float h, float density, float friction, float restitution, float angleDamp,
         QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
    Bird(x, y,
         w, h, density, friction, restitution, angleDamp,
         timer, pixmap, world, scene)
{
    HP = 1000;
    setB2dInterface(x, y, w , h, density, friction, restitution, angleDamp);
    setQtInterface(pixmap, w, h);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&qt_body);

}

void Pig::behavior()
{

}
