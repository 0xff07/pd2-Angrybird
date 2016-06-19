#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

    mousePressState = 0;
    maxBirdNum = 2;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(WORLD_WIDTH,WORLD_HEIGHT),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(WORLD_WIDTH/2,FLOOR_HEIGHT/2,WORLD_WIDTH,FLOOR_HEIGHT,QPixmap("").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
    //for(int i = 0; i < maxBirdNum; i++){
    Bird *birdie = new Bird(0.0f + BIRD_SIZE*6, FLOOR_HEIGHT * 1.5 , BIRD_SIZE, BIRD_SIZE,
                              BIRD_DENSITY , 0.2, 0.5, 3,
                          &timer,QPixmap(":/bird.png").scaled(64, 64),
                          world,scene);
    // Setting the Velocity
    birdList.push_back(birdie);
    //}
    YellowBird *YBird = new YellowBird(0.0f + BIRD_SIZE*4, FLOOR_HEIGHT * 1.5 , BIRD_SIZE, BIRD_SIZE,
                                 BIRD_DENSITY , 0.2, 0.5, 3,
                             &timer,QPixmap(":/image/YellowBird.png").scaled(64, 64),
                             world,scene);
    birdList.push_back((Bird*)YBird);

    IceBird *IBird = new IceBird(0.0f + BIRD_SIZE*2, FLOOR_HEIGHT * 1.5 , BIRD_SIZE, BIRD_SIZE,
                                 BIRD_DENSITY , 0.2, 0.5, 3,
                             &timer,QPixmap(":/image/BlackBird.png").scaled(64, 64),
                             world,scene);

    birdList.push_back((Bird*)IBird);


    WhiteBird *WBird = new WhiteBird(0.0f + BIRD_SIZE, FLOOR_HEIGHT * 1.5 , BIRD_SIZE, BIRD_SIZE,
                                 BIRD_DENSITY , 0.2, 0.5, 3,
                             &timer,QPixmap(":/image/WhiteBird.png").scaled(64, 64),
                             world,scene);
    birdList.push_back((Bird*)WBird);


    setGameScene();

    // Timer
      connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
      connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
      timer.start(100/6);

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    static QPointF mouseClickPos;
    static QPointF mouseReleasePos;

    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mousepress = static_cast< QMouseEvent* >(event);
        mouseClickPos =  mousepress -> pos();
        mousePressState = 1;
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* add rotation effect on objects */
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        if(mousePressState)
        {
          QMouseEvent *mouserelease = static_cast<QMouseEvent*>(event);
          mouseReleasePos =  mouserelease -> pos();
          mousePressState = 0;
          b2Vec2 displacement(mouseClickPos.x() - mouseReleasePos.x(),
                              mouseClickPos.y() - mouseReleasePos.y());
          if(Bird::currentBirdNo < maxBirdNum){
             QList<Bird*>::iterator it = birdList.begin() + Bird::currentBirdNo;
             (*it) -> setLinearVelocity(b2Vec2(displacement.x * 10, displacement.y * 10 * -1));
             (*it) -> setGravityEffect(9.8);
             (*it) -> shooted = 1;
             Bird::currentBirdNo++;
          }
        }

        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::setGameScene()
{
    rectList.clear();
    pigList.clear();

    for(int i = 0; i < 3; i++){
        Bird *pig_temp = new Bird(80.0f + BIRD_SIZE*(3 - i)*4, FLOOR_HEIGHT * 1.5 , BIRD_SIZE, BIRD_SIZE,
                                BIRD_DENSITY*10 , 10, 0.1, 10,
                            &timer,QPixmap(":/image/Pig.png").scaled(64, 64),
                            world,scene);
      // Setting the Velocity
        temp.push_back(pig_temp
                           );


    }

}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
     QList<Bird*>::iterator it = birdList.begin() + Bird::currentBirdNo;
     if(!((*it)->skillUsed)){
         (*it)->behavior();
     }
}








void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
