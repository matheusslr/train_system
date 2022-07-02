#ifndef TREM_H
#define TREM_H

#include "trail.h"

class Trem
{   
public:
    int x, y;
    int x_trilho, y_trilho;
    int largura, altura;
    bool status;
    int r, g, b;

    Trem(int x, int y, int x_trilho, int y_trilho, int largura, int altura, int r, int g, int b, bool status);
};

#endif // TREM_H
