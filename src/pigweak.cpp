#include "pigweak.h"

PigWeak::PigWeak(SAME_AS_BIRD):Bird(BIRD_VARIABLES)
{
    HP = 10000;
}

void PigWeak::behavior()
{
    return;
}

void PigWeak::collision()
{
     qDebug() << "in collision";
     qt_body.setPixmap(QPixmap(":/image/Pig_hitted.png").scaled(64, 64));
}
