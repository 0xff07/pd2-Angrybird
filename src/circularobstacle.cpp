#include "circularobstacle.h"

CircularObstacle::CircularObstacle(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{
    HP = 10000;
    setB2dInterface(x, y, w , h, density, friction, restitution, angleDamp);
    setQtInterface(pixmap, w, h);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&qt_body);
}

void CircularObstacle::behavior()
{

}
