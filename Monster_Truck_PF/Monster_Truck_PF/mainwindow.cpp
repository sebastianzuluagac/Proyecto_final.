#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    n1=new nivel;
    //n1->CARGAR_MUNDO();
    scene=n1->getlevel();
    ui->escena->setScene(scene);

    //camara de juego
    ui->escena->setEnabled(false);
    ui->escena->setHidden(true);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);

    carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    ui->escena->setScene(scene);

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
        if(carro->Carro_apoyado() == true) carro->Mover((carro->Fuerza_actual(0))-2.0, carro->Fuerza_actual(1));
      }break;
   //---------------------------------------
    case Qt::Key_D: {
        if(carro->Carro_apoyado() == true) carro->Mover((carro->Fuerza_actual(0))+2.0, carro->Fuerza_actual(1));
    }break;
    //-----------------------------
    //-----------------------------
    case Qt::Key_L: {
       ui->escena->setEnabled(true);
       ui->escena->setHidden(true);
       //ui->widget->show();

      }break;
   //---------------------------------------
    case Qt::Key_K: {
        ui->escena->setEnabled(false);
        ui->escena->setHidden(false);
        //ui->widget->hide();

      }break;
    //---------------------------------------
    case Qt::Key_W: {
        if(carro->Carro_apoyado() == true) carro->Mover(carro->Fuerza_actual(0), Fuerza_salto);
    }
    //-------------------------------------
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
        //interfaz de login
        ui->inicio->hide();
        //jugar y tienda
        ui->jugar->setEnabled(true);
        ui->jugar->setHidden(false);
        ui->tienda->setEnabled(true);
        ui->tienda->setHidden(false);

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


void MainWindow::on_jugar_clicked()
{
    //jugar
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    //niveles
    ui->niveles->setEnabled(true);
    ui->niveles->setHidden(false);
}


void MainWindow::on_nivel1_clicked()
{
    n1->CARGAR_MUNDO('1');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);

}


void MainWindow::on_nivel2_clicked()
{
    n1->CARGAR_MUNDO('2');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);
}


void MainWindow::on_nivel3_clicked()
{
    n1->CARGAR_MUNDO('3');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);
}


void MainWindow::on_nivel4_clicked()
{
    n1->CARGAR_MUNDO('4');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);
}

