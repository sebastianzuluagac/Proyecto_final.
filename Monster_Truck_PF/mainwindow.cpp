#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->widget->setGeometry(0,0,width()-3,800);
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);

    //ui->login->setGeometry(0,0,1345,tamnivelY);
    inicio = new QGraphicsScene;
    inicio->setSceneRect(0,0,width(),height());
    //ui->login->setScene(inicio);

    //ui->escena->setGeometry(0,0,tamnivelX,tamnivelY);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,tamnivelX, tamnivelY);
    ui->escena->setScene(scene);

    ui->escena->setEnabled(false);
    ui->escena->setHidden(true);


    QPixmap fondo(":/SPRITES_GAME/niveles/nivel1.png");
    QBrush fon2(Qt::black);
    ui->escena->setBackgroundBrush(fondo);
    //ui->login->setBackgroundBrush(fon2);

    n1=new nivel;
    carro=new personaje;
    carro->set_sprite(0,0);
    scene->addItem(carro);
    ui->escena->setScene(scene);
    carro->setPos(0,397);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animacion_ruedo()));
    //timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    static char dire= ' ';
    switch (tecla->key()){

    //--------------------------------------
     case Qt::Key_M: {
        ui->escena->scale(1.5,1.5);


       }break;
    //---------------------------------------
    case Qt::Key_N: {
    ui->escena->scale(0.5,0.5);

   }break;
//---------------------------------------
    case Qt::Key_A: {
        carro->MOVER_ATRAS();
        //carro->x()>0? carro->setX(carro->x()-10): carro->setX(carro->x());
        carro->x()>400? scene->setSceneRect(carro->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);
        dire='A';

      }break;
   //---------------------------------------
   case Qt::Key_D: {
   carro->MOVER_ADELANTE();
   carro->x()>400? scene->setSceneRect(carro->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);
   dire='D';
  }break;

    //-----------------------------
    case Qt::Key_L: {
       ui->escena->setEnabled(true);
       ui->escena->setHidden(true);

      // ui->login->setEnabled(false);
      // ui->login->setHidden(false);


      }break;
   //---------------------------------------
    case Qt::Key_K: {
        ui->escena->setEnabled(false);
        ui->escena->setHidden(false);

       // ui->login->setEnabled(true);
       // ui->login->setHidden(true);

    //LOGIN("nada","nada2");

      }break;
    //---------------------------------------

         case Qt::Key_P: {

        qDebug() <<"Press P" <<endl;
         LOGIN("nada","nada2");
         LOGIN("linea3","nada2");

           }break;
     //---------------------------------------

    }
    if (dire=='D'){
        //carro->INERCIA_ADELANTE();
        qDebug() <<"inerfcia adelante" <<endl;
        dire=' ';
    }
    else if (dire=='A'){
        //carro->INERCIA_ATRAS();
         qDebug() <<"inerfcia atras" <<endl;
        dire=' ';
    }
}

void MainWindow::animacion_ruedo()
{

}



void MainWindow::on_ingresar_clicked()
{

}

