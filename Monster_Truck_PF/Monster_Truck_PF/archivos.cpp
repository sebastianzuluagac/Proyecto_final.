#include "archivos.h"
#include <string>



bool GUARDAR_ESTADO(personaje car)
{   string linea;
    fstream file;
    file.open("datos_guardados.txt",fstream::in|fstream::app);
    if(file.is_open()){

        linea.append("N");
        linea.append(to_string(car.x()));
        linea.append("\t");
        linea.append("Y");
        linea.append(to_string(car.y()));

        file<<linea;
        linea="";
        file.close();

        return true;
    }
    else return false;
}

bool CREAR_USUARIO(string nameU, string pass)
{
    string linea;
        fstream file;
        file.open("../Monster_Truck_PF/datos.txt",fstream::in|fstream::app);
        if(file.is_open()){

            linea.append(nameU);
            linea.append("\t");
            linea.append(pass);
            linea.append("\n");
            file<<linea;
            //linea="";
            file.close();

            return true;
        }
        else return false;
}

bool LOGIN(string nameU, string pass)
{

    char* linealeida;
    fstream file;
    long long tam=0;
    file.open("../Monster_Truck_PF/datos.txt",fstream::ate | fstream::in );
    if (file.is_open()){
        tam=file.tellg();
        file.seekg(0);
        linealeida=new char [tam];
        while(file.eof()==false){
            file.getline(linealeida,tam);
            if(in(linealeida,nameU)){
                if(in(linealeida,pass)){
                    qDebug() <<"TODO ES CORRECTO" <<endl;
                    return true;
                    break;
                }
                else qDebug()<<"contraseña invalida"<<endl;return false; break;
            }
            else qDebug()<<"Usuario invalido"<<endl;

        }
        file.close();
        delete[] linealeida;
     }
     else qDebug()<<"no se pudo abrir "<<endl; return false;
}

bool CARGAR_ESTADO()
{
    string linea;
        fstream file;
        file.open("datos_guardados.txt",fstream::in|fstream::app);
        if(file.is_open()){

            linea.append("X");
            //linea.append();

            file<<linea;
            linea="";
            file.close();

            return true;
        }
        else return false;
}

bool in(string cadena, string palabra)
{
    bool esta=false;
    unsigned long long cont=0;
    for (unsigned long long i=0; i<cadena.size();i++){
        if (cadena[i]==palabra[0]) {
            for (unsigned long long k=0; k<palabra.size();k++){
                if (cadena[i+k]==palabra[k])cont++;
            }
            if (cont==palabra.size()) {
                esta=true;
                i=cadena.size()+10;
            }
            else cont=0;
        }
    }

    return esta;
}

string Datos_nivel(string Ruta)
{
    string Texto_String;
    fstream Archivo;
    Archivo.open (Ruta, fstream::in | fstream::binary);
    if(Archivo.is_open()){
        while (!Archivo.eof()) {
            Texto_String.push_back(Archivo.get())  ;
        }
    }
    Archivo.close();
    return Texto_String;
}
