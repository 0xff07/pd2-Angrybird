#include "contectlistener.h"
#include <QDebug>

ContectListener::ContectListener()
{
    qDebug() <<  "??";
}

void ContectListener::BeginContact(b2Contact *contact)
{
    qDebug() << "End";
    static_cast<GameItem*>(contact->GetFixtureA()->GetBody()->GetUserData())->collision();
    static_cast<GameItem*>(contact->GetFixtureB()->GetBody()->GetUserData())->collision();
}
