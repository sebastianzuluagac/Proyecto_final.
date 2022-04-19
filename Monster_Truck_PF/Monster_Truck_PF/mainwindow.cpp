#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    Niveles=new nivel;
    scene=Niveles->getlevel();
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
    //Boton atras
    ui->home->setEnabled(false);
    ui->home->setHidden(true);
    //Cantidad de monedas
    ui->icon_money->setEnabled(false);
    ui->icon_money->setHidden(true);
    ui->cant_money->setEnabled(false);
    ui->cant_money->setHidden(true);
    //vida del jugador
    ui->vidaP->setEnabled(false);
    ui->vidaP->setHidden(true);
    //Botones de escoger y comprar
    ui->L->setEnabled(false);
    ui->L->setHidden(true);
    ui->R->setEnabled(false);
    ui->R->setHidden(true);
    ui->buy->setEnabled(false);
    ui->buy->setHidden(true);
    ui->seleccionar->setEnabled(false);
    ui->seleccionar->setHidden(true);
    //Declaracion temporizador de juego activo.
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(Juego_activo()));    
    //Escena.
    ui->escena->setScene(scene);
    //Enviar direccion de vectores de objetos que añadiran los niveles.
    Niveles->Recibir_vectores(&Box, &Pincho, &Money, &Contenedores, &Mina, &Dama, &Aves);
}

MainWindow::~MainWindow()
{
    Niveles->Eliminar_memoria_vectores();
    carro->Destruirse();
    delete timer;
    delete Niveles;
    delete ui;
}

void MainWindow::Detener_juego()
{
    Niveles->Eliminar_memoria_vectores();
    carro->Destruirse();
    ui->escena->setEnabled(true);
    ui->escena->setHidden(true);
    //jugar y tienda
    ui->jugar->setEnabled(true);
    ui->jugar->setHidden(false);
    ui->tienda->setEnabled(true);
    ui->tienda->setHidden(false);
    //niveles
    ui->niveles->setEnabled(true);
    ui->niveles->setHidden(false);
}

void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    switch (tecla->key()){

    //--------------------------------------
    //Aplicar fuerza hacia delante si se esta apoyado, en caso contrario aplicar fuerza angular.
    case Qt::Key_A: {
        if(carro->Carro_apoyado()==true && carro->Datos(2)>-70 && carro->Datos(2)<70){
            carro->Mover((carro->Datos(0))-2.0, carro->Datos(1));
        }
        else
            if(carro->Colsionando() == false) carro->Girar((carro->Datos(5))+0.02, 10);
      }break;
   //---------------------------------------
   //Aplicar fuerza hacia atras si se esta apoyado, en caso contrario aplicar fuerza angular.
    case Qt::Key_D: {
        if(carro->Carro_apoyado()==true && carro->Datos(2)>-70 && carro->Datos(2)<70){
            carro->Mover((carro->Datos(0))+2.0, carro->Datos(1));
        }
        else
            if(carro->Colsionando() == false) carro->Girar((carro->Datos(5))-0.02, 10);
    }break;
    //-----------------------------
    //---------------------------------------
    //Aplicar fuerza hacia arriba si se esta apoyado.
    case Qt::Key_W: {
        if(carro->Carro_apoyado() == true) carro->Mover(carro->Datos(0), Fuerza_salto);
    }
    //-------------------------------------
    }
}

void MainWindow::Juego_activo()
{
    //+++++++++//
    //Inicio de interaccion colision con contenedores.
    for(int i = 0; i < Contenedores.length(); i++){
        if(carro->collidesWithItem(Contenedores[i])){            
            if(Contenedores[i]->Datos(2) != 0){
                if(((Contenedores[i]->Datos(0))-carro->Datos(3))>25){
                    //0.548
                    carro->Girar(0.066/((Contenedores[i]->Datos(0))-carro->Datos(3))*Contenedores[i]->Datos(2), 10);
                    carro->Punto_colision(Contenedores[i]->Datos(0), 300-Contenedores[i]->Datos(2)*3);
                }
                else if(((Contenedores[i]->Datos(0))-carro->Datos(3))<25){
                    carro->Girar(0.066/25*Contenedores[i]->Datos(2), 10);
                    float Altura_container;
                    Altura_container = (Contenedores[i]->Datos(0)-carro->Datos(3))*tan(Contenedores[i]->Datos(2)*3.14159265/180);
                    carro->Limite_inf(500-Altura_container-15);
                    carro->Punto_colision(Contenedores[i]->Datos(0), 300-Contenedores[i]->Datos(2)*3);
                }
                Colision = true;
                break;
            }
            else if(Contenedores[i]->Datos(2) == 0){
                if(carro->Datos(4) > Contenedores[i]->Datos(1)){
                    if(carro->Datos(3) < Contenedores[i]->Datos(0)){
                        carro->Choque_frontal(Contenedores[i]->Datos(0)-140 , carro->Datos(0));
                    }
                    else if(carro->Datos(3) > Contenedores[i]->Datos(0)){
                        carro->Choque_frontal(Contenedores[i]->Datos(0)+Contenedores[i]->Datos(3)+20, carro->Datos(0));
                    }
                }
                else{
                    carro->Limite_inf(Contenedores[i]->Datos(1)-74);
                }
                carro->Punto_colision(Contenedores[i]->Datos(0), Contenedores[i]->Datos(3));
                if(carro->Datos(2) > 0) carro->Girar(0, 10);
            }
            Colision = true;
        }
    }
    carro->Carro_colisionando(Colision);
    Colision = false;
    //Fin de interaccion colision con contenedores.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision con pinchos.
    for(int i = 0; i < Pincho.length(); i++){
        if(carro->collidesWithItem(Pincho[i])){
            Jugando = false;
        }
    }
    //Fin de interaccion colision con pinchos.
    //++++++++//

    //Detener ejecucion del juego.
    if(Jugando == false){
        timer->stop();
        Detener_juego();
    }
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
        //Cantidad de monedas
        ui->icon_money->setEnabled(true);
        ui->icon_money->setHidden(false);
        ui->cant_money->setEnabled(true);
        ui->cant_money->setHidden(false);
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
    //Boton atras
    ui->home->setEnabled(true);
    ui->home->setHidden(false);
}


void MainWindow::on_nivel1_clicked()
{
    Niveles->CARGAR_MUNDO('1');
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
    //vida del jugador
    ui->vidaP->setEnabled(true);
    ui->vidaP->setHidden(false);
    //Anadir personaje a la escena
    carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel2_clicked()
{
    Niveles->CARGAR_MUNDO('2');
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
    //vida del jugador
    ui->vidaP->setEnabled(true);
    ui->vidaP->setHidden(false);
    //Anadir personaje a la escena
    carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel3_clicked()
{
    Niveles->CARGAR_MUNDO('3');
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
    //vida del jugador
    ui->vidaP->setEnabled(true);
    ui->vidaP->setHidden(false);
    //Anadir personaje a la escena
    carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel4_clicked()
{
    Niveles->CARGAR_MUNDO('4');
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
    //vida del jugador
    ui->vidaP->setEnabled(true);
    ui->vidaP->setHidden(false);
    //Anadir personaje a la escena
    carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}

void MainWindow::on_tienda_clicked()
{
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
    //Botones de escoger y comprar
    ui->L->setEnabled(true);
    ui->L->setHidden(false);
    ui->R->setEnabled(true);
    ui->R->setHidden(false);
    ui->buy->setEnabled(true);
    ui->buy->setHidden(false);
    ui->seleccionar->setEnabled(true);
    ui->seleccionar->setHidden(false);
    //Boton atras
    ui->home->setEnabled(true);
    ui->home->setHidden(false);


}


void MainWindow::on_home_clicked()
{
    //camara de juego
    ui->escena->setEnabled(false);
    ui->escena->setHidden(true);
    //Boton atras
    ui->home->setEnabled(false);
    ui->home->setHidden(true);
    //vida del jugador
    ui->vidaP->setEnabled(false);
    ui->vidaP->setHidden(true);
    //Botones de escoger y comprar
    ui->L->setEnabled(false);
    ui->L->setHidden(true);
    ui->R->setEnabled(false);
    ui->R->setHidden(true);
    ui->buy->setEnabled(false);
    ui->buy->setHidden(true);
    //jugar y tienda
    ui->jugar->setEnabled(true);
    ui->jugar->setHidden(false);
    ui->tienda->setEnabled(true);
    ui->tienda->setHidden(false);
    //Cantidad de monedas
    ui->icon_money->setEnabled(true);
    ui->icon_money->setHidden(false);
    ui->cant_money->setEnabled(true);
    ui->cant_money->setHidden(false);
    //niveles
    ui->niveles->setEnabled(false);
    ui->niveles->setHidden(true);

}
