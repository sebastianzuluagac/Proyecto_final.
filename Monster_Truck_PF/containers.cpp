#include "containers.h"

containers::containers(QString name)
{
    imagen.load(name);
    setPixmap(imagen);
    copia=imagen.copy(0,0,602, 209).scaled(602*0.5,209*0.5);
    setPixmap(copia);
}

containers::containers()
{

}
