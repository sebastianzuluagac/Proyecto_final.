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
    //Escena de la tienda.
    tienda= new QGraphicsScene;
    tienda->setSceneRect(0,0,400,400);
    //Llenar mapa de imagenes decorativas.
    Imagenes['g'] = new ima(0, 0, tamnivelX, tamnivelY, "../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/gameover.jpg");
    Imagenes['w'] = new ima(0, 0, 237, 212, "../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/winer.png");

    carro=new personaje(scene, 0, 500);

    //Carros en la tienda

    //Declaracion temporizador de juego activo.
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(Juego_activo()));    
    //Escena.
    ui->escena->setScene(scene);
    //Enviar direccion de vectores de objetos que añadiran los niveles.
    Niveles->Recibir_vectores(&Box, &Pincho, &Money, &Contenedores, &Mina, &Dama, &Aves, &Cierras, &Resortes, &Finish);
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
    if(Jugando == true){
        //delete carro;
        Jugando = false;
    }
    else Jugando = false;
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
    //Boton atras
    ui->home->setEnabled(true);
    ui->home->setHidden(false);
    scene->removeItem(Imagenes['g']);
    scene->removeItem(Imagenes['w']);
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
                        carro->Danio_vehiculo(carro->Datos(10)*0.005);
                    }
                    else if(carro->Datos(3) > Contenedores[i]->Datos(0)){
                        carro->Choque_frontal(Contenedores[i]->Datos(0)+Contenedores[i]->Datos(3)+20, carro->Datos(0));
                        carro->Danio_vehiculo(carro->Datos(10)*0.005);
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
            carro->Danio_vehiculo(carro->Datos(9));
        }
    }
    //Fin de interaccion colision con pinchos.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision con bombas.
    for(int i = 0; i < Mina.length(); i++){
        if(carro->collidesWithItem(Mina[i])){
            if(Mina[i]->Mina_activa() == true){
                carro->Danio_vehiculo(carro->Datos(10)*0.2);
                Mina[i]->Destruir_mina();
            }
        }
    }
    //Fin de interaccion colision con bombas.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision con aves.
    for(int i = 0; i < Aves.length(); i++){
        if(carro->collidesWithItem(Aves[i])){
            if(Aves[i]->Ave_activa() == true){
                carro->UPDATE_DATA('D', '+', 3);
                Aves[i]->Destruir_ave();
            }
        }
    }
    //Fin de interaccion colision con aves.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision con monedas.
    for(int i = 0; i < Money.length(); i++){
        if(carro->collidesWithItem(Money[i])){
            if(Money[i]->Moneda_activa() == true){
                carro->UPDATE_DATA('D', '+', 1);
                Money[i]->Destruir_moneda();
            }
        }
    }
    //Fin de interaccion colision con monedas.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision con cierras.
    for(int i = 0; i < Cierras.length(); i++){
        if(carro->collidesWithItem(Cierras[i])){
            if(carro->Datos(3) < Cierras[i]->Datos(0)){
                carro->Choque_frontal(Cierras[i]->Datos(0)-140 , Cierras[i]->Datos(2)*0.5);
                carro->Danio_vehiculo(carro->Datos(10)*0.05);
            }
            else if(carro->Datos(3) > Cierras[i]->Datos(0)){
                carro->Choque_frontal(Cierras[i]->Datos(0)+Cierras[i]->Datos(1)+20, -Cierras[i]->Datos(2)*0.5);
                carro->Danio_vehiculo(carro->Datos(10)*0.05);
            }
        }
    }
    //Fin de interaccion colision con cierras.
    //++++++++//


    //+++++++++//
    //Inicio de interaccion colision con resortes.
    for(int i = 0; i < Resortes.length(); i++){
        if(carro->collidesWithItem(Resortes[i])){
            if(carro->Datos(4) > Resortes[i]->Datos(1)){
                if(carro->Datos(3) < Resortes[i]->Datos(0)){
                    carro->Choque_frontal(Resortes[i]->Datos(0)-140, Resortes[i]->Datos(3)*10);
                }
                else if(carro->Datos(3) > Resortes[i]->Datos(0)){
                    carro->Choque_frontal(Resortes[i]->Datos(0)+Resortes[i]->Datos(2)+20, -Resortes[i]->Datos(3)*10);
                }
            }
            else if(carro->Datos(4) < Resortes[i]->Datos(1)){
                if(carro->Datos(3) < Resortes[i]->Datos(0)+(Resortes[i]->Datos(2)/2)){
                    carro->Mover(-Resortes[i]->Datos(3)*20, -Resortes[i]->Datos(3)*2);
                    carro->Limite_inf(Resortes[i]->Datos(1)-74);
                }
                else if(carro->Datos(3) > Resortes[i]->Datos(0)+(Resortes[i]->Datos(2)/2)){
                    carro->Mover(Resortes[i]->Datos(3)*20, -Resortes[i]->Datos(3));
                    carro->Limite_inf(Resortes[i]->Datos(1)-74);
                }
            }
        }
    }
    //Fin de interaccion colision con resortes.
    //++++++++//

    //+++++++++//
    //Inicio de interaccion colision capo con el suelo.
    if(carro->Carro_apoyado() == true && (carro->Datos(2) > 150 || carro->Datos(2) < -150)) carro->Danio_vehiculo(carro->Datos(10)*0.002);
    //Fin de interaccion colision con resortes.
    //++++++++//

    //Actualizar barra de estado y cantidad de monedas.
    ui->cant_money->display(carro->Datos(11));
    ui->vidaP->setValue(carro->Datos(9));

    //Detener ejecucion del juego si el vehiculo esta dañado completamente.
    if(carro->Datos(9) <= 0){
        Ganastes = false;
        timer->stop();
        GUARDAR_ESTADO(carro);
        Niveles->Eliminar_memoria_vectores();
        //Colocar aqui el fondo de finalizacion de juego.
        Imagenes['g']->setX(carro->x()-400);
        scene->addItem(Imagenes['g']);
        carro->Destruirse();
        ui->vidaP->setHidden(true);
        QTimer::singleShot(5000, this, SLOT(Detener_juego()));
    }

    //+++++++++//
    //Inicio de interaccion colision con la meta.
    if(carro->Datos(3) >= Finish->Datos()){
        Ganastes = true;
        timer->stop();
        GUARDAR_ESTADO(carro);
        Niveles->Eliminar_memoria_vectores();
        //Colocar aqui el fondo de finalizacion de juego.
        Imagenes['w']->setX(carro->x());
        Imagenes['w']->Escalar(237, 212, 2, 2);
        scene->addItem(Imagenes['w']);
        carro->Ganar();
        ui->vidaP->setHidden(true);
        QTimer::singleShot(5000, this, SLOT(Detener_juego()));
    }
    //Fin de interaccion colision con la meta.
    //++++++++//
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


        name=ui->username->text();
        carro->USERNAME(name);

        //Cargar los datos del usuario
        CARGAR_ESTADO(carro );
        ui->cant_money->display(carro->Datos(11));

    }
    else ui->respuesta->setText("Contraseña y/o nombre INVALIDOS");
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
    carro->Iniciar_nivel();
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
    //carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(50);
}


void MainWindow::on_nivel2_clicked()
{
    carro->Iniciar_nivel();
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
    //carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel3_clicked()
{
    carro->Iniciar_nivel();
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
    //carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel4_clicked()
{
    carro->Iniciar_nivel();
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
    //carro=new personaje(scene, 0, 500);
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}

void MainWindow::on_tienda_clicked()
{
    ui->escena->setEnabled(true);
    ui->escena->setHidden(false);
    ui->widget_2->setGeometry(0,0,800,420);
    ui->escena->setScene(tienda);
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
    //Carros en la tienda
    modelo=new ima(80, 120,240,153,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/personaje/carro1/carro_mounstro.png");
    modelo->set_sprite(0,nLR,240,153);
    tienda->addItem(modelo);

    if(carro->GET_DATA('C','D') >=nLR){
        ui->seleccionar->setEnabled(true);
        ui->buy->setEnabled(false);
        ui->precio->setText("Desbloqueado");
    }
}


void MainWindow::on_home_clicked()
{
    //camara de juego
    ui->escena->setEnabled(false);
    ui->escena->setHidden(true);
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setScene(scene);
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
    ui->seleccionar->setEnabled(false);
    ui->seleccionar->setHidden(true);
    ui->precio->setHidden(true);
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
    timer->stop();
    Detener_juego();
}

void MainWindow::on_R_clicked()
{   if (nLR<4)nLR++;
    modelo->set_sprite(0,nLR,240,153);

    string costoint=to_string(nLR*50);
    QString precio;
    if(carro->GET_DATA('C','D') >=nLR){
        ui->seleccionar->setEnabled(true);
        ui->buy->setEnabled(false);
        precio.append("Desbloqueado");
    }
    else {
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(true);

        precio.append("Costo: $");
        precio.append( QString::fromLocal8Bit(costoint.c_str()) );
    }
    ui->precio->setText(precio);


}


void MainWindow::on_L_clicked()
{
    if (nLR>0)nLR--;
    modelo->set_sprite(0,nLR,240,153);

    string costoint=to_string(nLR*50);
    int num=carro->GET_DATA('C','D');
    string carrosDes=to_string(num);
    QString precio;
    for(unsigned long i=0;i<carrosDes.size();i++){

        if( carrosDes[i]==nLR){
            ui->seleccionar->setEnabled(true);
            ui->buy->setEnabled(false);
            precio.append("Desbloqueado");
            GUARDAR_ESTADO(carro);
        }
        else {
            ui->seleccionar->setEnabled(false);
            ui->buy->setEnabled(true);

            precio.append("Costo: $");
            precio.append( QString::fromLocal8Bit(costoint.c_str()) );
        }
    }
    ui->precio->setText(precio);



}


void MainWindow::on_seleccionar_clicked()
{
    ui->seleccionar->setEnabled(false);
    carro->UPDATE_DATA('C','E',nLR);

}

void MainWindow::on_buy_clicked()
{
    ui->buy->setEnabled(false);

    string n=to_string(nLR*50);
    QString mensaje;
    if(carro->GET_DATA('D',' ') >=nLR*50){
        ui->seleccionar->setEnabled(true);
        ui->buy->setEnabled(false);
        carro->UPDATE_DATA('C','E',nLR);//Se escoge el carro automaticamente el comprar
        carro->UPDATE_DATA('D','-',nLR*50);//Se hace el cobro del carro
        mensaje.append("Compra Exitosa!!✅");
    }
    else {
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(true);

        mensaje.append("Saldo Insuficiente!!❌");
    }
    ui->precio->setText(mensaje);
    ui->cant_money->display(carro->Datos(11));

}
