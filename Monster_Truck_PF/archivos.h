#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "personaje.h"
#include <fstream>
#include <string.h>

using namespace std;

bool GUARDAR_ESTADO();

bool CARGAR_ESTADO();

bool LOGIN();

bool CREAR_USUARIO(string nameU, string pass);

#endif // ARCHIVOS_H
