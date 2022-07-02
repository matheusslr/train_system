#include "trem.h"
#include "trail.h"

Trem::Trem(int x, int y,int x_trilho, int y_trilho, int largura, int altura, int r, int g, int b, bool status=0)
{
    this->x = x;
    this->y = y;
    this->x_trilho = x_trilho;
    this->y_trilho = y_trilho;
    this->largura = largura;
    this->altura = altura;
    this->r = r;
    this->g = g;
    this->b = b;
    this->status = status;
}
