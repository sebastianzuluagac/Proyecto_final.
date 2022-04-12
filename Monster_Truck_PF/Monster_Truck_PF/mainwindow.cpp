#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->widget->setGeometry(0,0,width()-3,800);
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);

    inicio = new QGraphicsScene;
    inicio->setSceneRect(0,0,width(),height());

    //ui->escena->setGeometry(0,0,tamnivelX,tamnivelY);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,tamnivelX, tamnivelY);
    ui->escena->setScene(scene);

    ui->escena->setEnabled(false);
    ui->escena->setHidden(true);


    QPixmap fondo(":/SPRITES_GAME/niveles/nivel1.png");
    ui->escena->setBackgroundBrush(fondo);


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
    switch (tecla->key()){

    //--------------------------------------
    case Qt::Key_A: {
        carro->MOVER_ATRAS();
        //carro->x()>0? carro->setX(carro->x()-10): carro->setX(carro->x());
        carro->x()>400? scene->setSceneRect(carro->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);

      }break;
   //---------------------------------------
   case Qt::Key_D: {
   carro->MOVER_ADELANTE();
   carro->x()>400? scene->setSceneRect(carro->x()-400,0,tamnivelX, tamnivelY):scene->setSceneRect(0,0,tamnivelX, tamnivelY);

  }break;

    //-----------------------------
    case Qt::Key_L: {
       ui->escena->setEnabled(true);
       ui->escena->setHidden(true);
       ui->widget->show();

      }break;
   //---------------------------------------
    case Qt::Key_K: {
        ui->escena->setEnabled(false);
        ui->escena->setHidden(false);
        ui->widget->hide();

      }break;
    //---------------------------------------

    }
}

void MainWindow::animacion_ruedo()
{

}



void MainWindow::on_ingresar_clicked()
{
    qDebug() <<"click" <<endl;
    if(LOGIN(ui->username->text().toStdString(),ui->pw->text().toStdString())){
        ui->respuesta->setText("Ingreso Exitoso");
        ui->escena->setEnabled(false);
        ui->escena->setHidden(false);
        ui->widget->hide();
    }
    else ui->respuesta->setText("Ingreso Fallido");

}




void MainWindow::on_crearU_clicked()
{
    if(CREAR_USUARIO(ui->username->text().toStdString(),ui->pw->text().toStdString())){
        ui->respuesta->setText("Registro Exitoso");

    }
    else ui->respuesta->setText("Registro Fallido");
}

