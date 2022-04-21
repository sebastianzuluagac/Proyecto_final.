#include "archivos.h"
#include <string>
#include <QString>



bool GUARDAR_ESTADO(personaje *car)
{
    bool estuvo=false;
    string line,linea,DATOS;
    fstream file;
    file.open("../Monster_Truck_PF/datos_guardados.txt",fstream::binary | fstream::in );
    if (file.is_open()){
        while(file.eof()==false){
            getline(file, line);
            if(in(line, car->GET_NAME().toStdString() )){
                estuvo=true;
                linea=FORMATOLINEA(car);
                DATOS.append(linea);
            }
            else {
                line.append("\n");
                DATOS.append(line);
            }
        }
        if (estuvo==false){//Si no estuvo en los datos guardados entonces crea otro
            linea=FORMATOLINEA(car);
            DATOS.append(linea);
        }
        file.close();
     }
     else qDebug()<<"no se pudo abrir "<<endl;


//------Escribir en el archivo la nueva informacion...
    file.open("../Monster_Truck_PF/datos_guardados.txt",fstream::out | fstream::binary);
    if(file.is_open()){

        file<<DATOS;
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
            //else qDebug()<<"Usuario invalido"<<endl;

        }
        file.close();
        delete[] linealeida;
     }
     else qDebug()<<"no se pudo abrir "<<endl; return false;
}

bool CARGAR_ESTADO(personaje *car)
{
    char* linealeida;
    int indx=0,n=0,N,D;
    string line,C;
    fstream file;
    long long tam=0;
    file.open("../Monster_Truck_PF/datos_guardados.txt",fstream::binary | fstream::ate | fstream::in );
    if (file.is_open()){
        tam=file.tellg();
        file.seekg(0);
        linealeida=new char [tam];
        while(!file.eof()){
             qDebug()<<"eof  "<<file.eof()<<endl;
            file.getline(linealeida,tam);
            if(in(linealeida, car->GET_NAME().toStdString() )){

                line=linealeida;
                indx=line.find(':',0);

                n=( line.find('n',indx) )-( line.find('N',indx)+1 );
                N=stoi( line.substr(line.find('N',0)+1,n) );

                n=( line.find('c',indx) )-( line.find('C',indx)+1 );
                C=line.substr(line.find('C',0)+1,n);

                n=( line.find('d',indx) )-( line.find('D',indx)+1 );
                D= stoi( line.substr(line.find('D',indx)+1,n) );

               car->SETDATA(D,C,N);
            }
            //else qDebug()<<"Usuario invalido"<<endl;

        }
        file.close();
        delete[] linealeida;
     }
     else qDebug()<<"no se pudo abrir "<<endl; return false;
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


string FORMATOLINEA(personaje *car)
{
    string linea;
    linea.append( car->GET_NAME().toStdString() );
    linea.append(":\t");
    linea.append("N");
    linea.append( to_string( car->GET_DATA('N',' ') ) );
    linea.append("n\t");
    linea.append("C");
    linea.append( to_string( car->GET_DATA('C','D') ) );
    linea.append("c\t");
    linea.append("D");
    linea.append( to_string( car->GET_DATA('D',' ') ) );
    linea.append("d");
    linea.append("\n");

    return linea;
}
