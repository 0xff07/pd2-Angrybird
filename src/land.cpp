#include "land.h"

Land::Land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    qt_body.setPixmap(pixmap);
    Qt_size = QSize(w,h);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    b2d_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox = setPolygonShape(w, h);
    b2d_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&qt_body);
    paint();
}
