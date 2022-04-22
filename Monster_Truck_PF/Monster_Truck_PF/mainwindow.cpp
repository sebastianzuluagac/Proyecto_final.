#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->widget_2->setGeometry(0,0,800,420);


    Niveles=new nivel;

    scene=Niveles->getlevel();

    inicio = new QGraphicsScene;
    inicio->setSceneRect(0,0,800,400);
    ui->escena->setScene(inicio);//escena con la portada del juego

    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->jugar_2->setEnabled(false);
    ui->jugar_2->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->nivel1->setEnabled(false);
    ui->nivel1->setHidden(true);
    ui->nivel2->setEnabled(false);
    ui->nivel2->setHidden(true);
    ui->nivel3->setEnabled(false);
    ui->nivel3->setHidden(true);
    ui->nivel4->setEnabled(false);
    ui->nivel4->setHidden(true);
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
    tienda->setSceneRect(0,0,805,420);
    //Llenar mapa de imagenes decorativas.
    decorar();
    //se crea el personaje pero no se agrega todavia a la escena
    carro=new personaje(scene, 0, 500);

    //Declaracion temporizador de juego activo.
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(Juego_activo()));    

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

void MainWindow::addeco(char indx, int posx, int posy, int tamx, int tamy, float escx, float escy, QString name)
{
    QString direccion="../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/decoracion/";
    direccion.append(name);
    Imagenes[indx] = new ima(posx,posy,tamx,tamy,direccion);
    Imagenes[indx]->Escalar(tamx,tamy,escx,escy);
    scene->addItem(Imagenes[indx]);

}

void MainWindow::decorar()
{
    Imagenes['g'] = new ima(0, 0, tamnivelX, tamnivelY, "../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/gameover.jpg");
    Imagenes['w'] = new ima(0, 0, 237, 212, "../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/winer.png");
    Imagenes['N'] = new ima(0,0,800,400,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/decoracion/fondo_niveles.png");
    Imagenes['L'] = new ima(0,0,800,400,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/decoracion/portada21.png");
    Imagenes['I'] = new ima(0,0,800,400,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/decoracion/portada2.png");
    Imagenes['T'] = new ima(0,0,800,400,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/objetos/decoracion/taller.png");
    Imagenes['F'] = new ima(0,0,1280,516,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/niveles/fondo.png");
    Imagenes['F']->Escalar(1280,516,1.08,1);
    scene->addItem(Imagenes['F']);
    inicio->addItem(Imagenes['L']);
    tienda->addItem(Imagenes['T']);

    //agregar las ecoraciones a la escena
    addeco('1',300,205,408,183,1.57,1.70,"supermarket.png");
    addeco('5',3550,-48,377,376,1.5,1.5,"edificio.png");
    addeco('2',4050,41,386,317,1.5,1.5,"edificio2pisos.png");
    addeco('3',4550,138,375,315,1.2,1.2,"garaje.png");
    addeco('4',6039,138,546,315,1.2,1.2,"garaje2.png");
    addeco('a',2000,179,280,337,0.8,1,"arbol.png");
    addeco('a',8681,179,280,337,0.8,1,"arbol.png");
    addeco('a',9032,179,280,337,0.8,1,"arbol.png");
    addeco('5',10171,-48,377,376,1.5,1.5,"edificio.png");
    addeco('2',10671,41,386,317,1.5,1.5,"edificio2pisos.png");
    addeco('3',11171,138,375,315,1.2,1.2,"garaje.png");
    addeco('1',13551,205,408,183,1.57,1.70,"supermarket.png");
    addeco('4',15366,138,546,315,1.2,1.2,"garaje2.png");
    addeco('a',17133,179,280,337,0.8,1,"arbol.png");
    addeco('a',17333,179,280,337,0.8,1,"arbol.png");
    addeco('a',17533,179,280,337,0.8,1,"arbol.png");
    addeco('a',17733,179,280,337,0.8,1,"arbol.png");
    addeco('a',19133,179,280,337,0.8,1,"arbol.png");
    addeco('a',19333,179,280,337,0.8,1,"arbol.png");
    addeco('a',19533,179,280,337,0.8,1,"arbol.png");
    addeco('a',19733,179,280,337,0.8,1,"arbol.png");
    addeco('3',20425,138,375,315,1.2,1.2,"garaje.png");
    addeco('a',21200,179,280,337,0.8,1,"arbol.png");
    addeco('a',21350,179,280,337,0.8,1,"arbol.png");
    addeco('a',21500,179,280,337,0.8,1,"arbol.png");

    addeco('a',22550,179,280,337,0.8,1,"arbol.png");
    addeco('a',22750,179,280,337,0.8,1,"arbol.png");
    addeco('5',23000,-48,377,376,1.5,1.5,"edificio.png");
    addeco('2',23500,41,386,317,1.5,1.5,"edificio2pisos.png");
    addeco('3',24000,138,375,315,1.2,1.2,"garaje.png");

    addeco('5',25000,-48,377,376,1.5,1.5,"edificio.png");
    addeco('2',25500,41,386,317,1.5,1.5,"edificio2pisos.png");
    addeco('3',26000,138,375,315,1.2,1.2,"garaje.png");
    addeco('a',26500,179,280,337,0.8,1,"arbol.png");
    addeco('a',26700,179,280,337,0.8,1,"arbol.png");

}


void MainWindow::Detener_juego()
{
    on_home_clicked();
    on_jugar_clicked();

    scene->removeItem(Imagenes['g']);
    scene->removeItem(Imagenes['w']);
}

void MainWindow::keyPressEvent(QKeyEvent *tecla)
{
    switch (tecla->key()){

        //--------------------------------------
        //Aplicar fuerza hacia delante si se esta apoyado, en caso contrario aplicar fuerza angular.
        case Qt::Key_A: {
        qDebug()<<"X: "<<carro->x()<<"\nY: "<<carro->y()<<endl;
            if(carro->Carro_apoyado()==true && carro->Datos(2)>-70 && carro->Datos(2)<70){
                carro->Mover((carro->Datos(0))-2.0, carro->Datos(1));
            }
            else
                if(carro->Colsionando() == false) carro->Girar((carro->Datos(5))+0.02, 10);
          }break;
       //---------------------------------------
       //Aplicar fuerza hacia atras si se esta apoyado, en caso contrario aplicar fuerza angular.
        case Qt::Key_D: {
        qDebug()<<"X: "<<carro->x()<<"\nY: "<<carro->y()<<endl;
            if(carro->Carro_apoyado()==true && carro->Datos(2)>-70 && carro->Datos(2)<70){
                carro->Mover((carro->Datos(0))+2.0, carro->Datos(1));
            }
            else
                if(carro->Colsionando() == false) carro->Girar((carro->Datos(5))-0.02, 10);
        }break;
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
        Imagenes['g']->Escalar(1280, 720, 1.08, 1.11);
        carro->Destruirse();
        ui->vidaP->setHidden(true);
        QTimer::singleShot(5000, this, SLOT(Detener_juego()));
        //Tfondo->stop();
    }

    //+++++++++//
    //Inicio de interaccion colision con la meta.
    if(carro->Datos(3) >= Finish->Datos()){
        Ganastes = true;
        timer->stop();
        carro->UPDATE_DATA('N',' ',1);
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

        carro->USERNAME(ui->username->text());

        //Cargar los datos del usuario
        CARGAR_ESTADO(carro );
        ui->cant_money->display(carro->Datos(11));

        inicio->addItem(Imagenes['I']);
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
    //tienda
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);

    //niveles
    ui->nivel1->setEnabled(true);
    ui->nivel1->setHidden(false);
    ui->nivel2->setHidden(false);
    ui->nivel3->setHidden(false);
    ui->nivel4->setHidden(false);
    if(carro->GET_DATA('N',' ')>=2){
        ui->nivel2->setEnabled(true);
    }
    if(carro->GET_DATA('N',' ')>=3){
        ui->nivel3->setEnabled(true);
    }
    if(carro->GET_DATA('N',' ')>=4){
        ui->nivel4->setEnabled(true);
    }
    //se cambia de imagen y de escena por la que corresponde a la seleccion de nivel
    inicio->addItem(Imagenes['N']);
    ui->escena->setScene(inicio);
}


void MainWindow::on_nivel1_clicked()
{
    //resetear la escena
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setScene(scene);

    carro->Iniciar_nivel(Imagenes['F']);
    Niveles->CARGAR_MUNDO('1');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //Boton atras
    ui->home->setEnabled(false);
    //jugar y tienda
    ui->jugar->setEnabled(false);
    ui->jugar->setHidden(true);
    ui->tienda->setEnabled(false);
    ui->tienda->setHidden(true);
    //niveles
    ui->nivel1->setEnabled(false);
    ui->nivel1->setHidden(true);
    ui->nivel2->setEnabled(false);
    ui->nivel2->setHidden(true);
    ui->nivel3->setEnabled(false);
    ui->nivel3->setHidden(true);
    ui->nivel4->setEnabled(false);
    ui->nivel4->setHidden(true);
    //vida del jugador
    ui->vidaP->setEnabled(true);
    ui->vidaP->setHidden(false);
    //Anadir personaje a la escena
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(50);
}


void MainWindow::on_nivel2_clicked()
{
    //resetear la escena
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setScene(scene);

    carro->Iniciar_nivel(Imagenes['F']);
    Niveles->CARGAR_MUNDO('2');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //Boton atras
    ui->home->setEnabled(false);
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
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel3_clicked()
{
    //resetear la escena
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setScene(scene);

    carro->Iniciar_nivel(Imagenes['F']);
    Niveles->CARGAR_MUNDO('3');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //Boton atras
    ui->home->setEnabled(false);
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
    carro->set_sprite(0,0);
    scene->addItem(carro);
    //Activar temporizador ciclo automatico.
    Jugando = true;
    timer->start(20);
}


void MainWindow::on_nivel4_clicked()
{
    //resetear la escena
    ui->widget_2->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setGeometry(0,0,1380,tamnivelY);
    ui->escena->setScene(scene);

    carro->Iniciar_nivel(Imagenes['F']);
    Niveles->CARGAR_MUNDO('4');
    ui->escena->setEnabled(false);
    ui->escena->setHidden(false);
    //Boton atras
    ui->home->setEnabled(false);
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
    ui->jugar_2->setEnabled(true);
    ui->jugar_2->setHidden(false);
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
    ui->precio->setHidden(false);
    //Boton atras
    ui->home->setEnabled(true);
    ui->home->setHidden(false);
    //Carros en la tienda
    nLR=carro->GET_DATA('C','E');
    modelo=new ima(280, 120,240,153,"../Monster_Truck_PF/MEDIA/SPRITES_GAME/personaje/carro1/carro_mounstro.png");
    modelo->set_sprite(0,nLR,240,153);
    tienda->addItem(modelo);
    if(carro->GET_DATA('C','E')==nLR){
        ui->seleccionar->setEnabled(false);
        ui->precio->setText("Seleccionado!✅");
    }
    else {
        ui->seleccionar->setEnabled(true);
        ui->precio->setText("Desbloqueado!!");
    }
    ui->buy->setEnabled(false);
}


void MainWindow::on_home_clicked()
{
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
    ui->jugar_2->setEnabled(false);
    ui->jugar_2->setHidden(true);
    ui->tienda->setEnabled(true);
    ui->tienda->setHidden(false);
    //Cantidad de monedas
    ui->icon_money->setEnabled(true);
    ui->icon_money->setHidden(false);
    ui->cant_money->setEnabled(true);
    ui->cant_money->setHidden(false);
    //niveles
    ui->nivel1->setEnabled(false);
    ui->nivel1->setHidden(true);
    ui->nivel2->setEnabled(false);
    ui->nivel2->setHidden(true);
    ui->nivel3->setEnabled(false);
    ui->nivel3->setHidden(true);
    ui->nivel4->setEnabled(false);
    ui->nivel4->setHidden(true);
    timer->stop();
    //Detener juego
    if(Jugando == true)Jugando = false;
    //camara de juego
    ui->escena->setEnabled(true);
    ui->escena->setHidden(false);
    ui->escena->setGeometry(0,0,800,420);
    //ui->widget_2->setGeometry(0,0,800,420);
    inicio->removeItem(Imagenes['N']);
    inicio->addItem(Imagenes['I']);
    ui->escena->setScene(inicio);

}

void MainWindow::on_R_clicked()
{   if (nLR<4)nLR++;
    modelo->set_sprite(0,nLR,240,153);

    string car,cardes=to_string( carro->GET_DATA('C','D') );
    cardes.insert(0,"0");
    QString precio;
    bool des=false;
    int num;
    for(unsigned long i=0;i<cardes.size();i++){
        car=cardes[i];
        num= stoi(car);
        if( num==nLR){
            des=true;
            break;
        }
    }
    if(des){
        if(carro->GET_DATA('C','E')==nLR){
            ui->seleccionar->setEnabled(false);
            precio.append("Seleccionado!✅");
        }
        else {
            ui->seleccionar->setEnabled(true);
            precio.append("Desbloqueado!!");
        }
        ui->buy->setEnabled(false);
        }
    else {
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(true);

        precio.append("Costo: $");
        precio.append( QString::fromLocal8Bit( (to_string(nLR*50)).c_str() ) );
    }
    ui->precio->setText(precio);
}


void MainWindow::on_L_clicked()
{
    if (nLR>0)nLR--;
    modelo->set_sprite(0,nLR,240,153);

    string car,cardes=to_string( carro->GET_DATA('C','D') );
    cardes.insert(0,"0");
    QString precio;
    bool des=false;
    int num;
    for(unsigned long i=0;i<cardes.size();i++){
        car=cardes[i];
        num= stoi(car);
        if( num==nLR){
            des=true;
            break;
        }
    }
    if(des){
        if(carro->GET_DATA('C','E')==nLR){
            ui->seleccionar->setEnabled(false);
            precio.append("Seleccionado!✅");
        }
        else {
            ui->seleccionar->setEnabled(true);
            precio.append("Desbloqueado!!");
        }
        ui->buy->setEnabled(false);
        }
    else {
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(true);

        precio.append("Costo: $");
        precio.append( QString::fromLocal8Bit( (to_string(nLR*50)).c_str() ) );
    }
    ui->precio->setText(precio);
}


void MainWindow::on_seleccionar_clicked()
{
    ui->seleccionar->setEnabled(false);
    carro->UPDATE_DATA('C','E',nLR);
    ui->precio->setText("Seleccionado!✅");
}

void MainWindow::on_buy_clicked()
{
    ui->buy->setEnabled(false);
    QString mensaje;
    if(carro->GET_DATA('D',' ') >=nLR*50){
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(false);
        carro->UPDATE_DATA('C','E',nLR);//Se escoge el carro automaticamente el comprar
        carro->UPDATE_DATA('D','-',nLR*50);//Se hace el cobro del carro
        carro->UPDATE_DATA('C','D',nLR);//Se acualiza la informacion corespondiente a los carros desbloqueados
        mensaje.append("Compra Exitosa!!✅");
        GUARDAR_ESTADO(carro);//Se guardan los datos actuales en la base de datos
    }
    else {
        ui->seleccionar->setEnabled(false);
        ui->buy->setEnabled(true);

        mensaje.append("Saldo Insuficiente!!❌");
    }
    ui->precio->setText(mensaje);
    ui->cant_money->display(carro->Datos(11));
}

void MainWindow::on_jugar_2_clicked()
{
    //jugar
    ui->jugar_2->setEnabled(false);
    ui->jugar_2->setHidden(true);

    on_home_clicked();
    on_jugar_clicked();
}

