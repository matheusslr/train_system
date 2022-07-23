#ifndef TREM_H
#define TREM_H

#include "trail.h"
#include <QtCore>

class Trem
{   
public:
    int x, y;
    int x_trilho, y_trilho, altura_trilho,largura_trilho;
    int largura, altura;
    bool status;
    int r, g, b;
    int movimento,velocidade;

    Trem(int x, int y, int x_trilho, int y_trilho, int largura, int altura,int largura_trilho, int altura_trilho, int r, int g, int b, bool status);
    void move();
    void setVel(int vel);
    int getTrilho();

};

#endif // TREM_H
