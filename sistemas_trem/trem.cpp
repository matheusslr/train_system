#include "trem.h"
#include "trail.h"


Trem::Trem(int x, int y,int x_trilho, int y_trilho, int largura, int altura, int largura_trilho, int altura_trilho,int r, int g, int b, bool status=0)
{
    this->x = x;
    this->y = y;
    this->x_trilho = x_trilho;
    this->y_trilho = y_trilho;
    this->largura = largura;
    this->altura = altura;
    this->largura_trilho = largura_trilho;
    this->altura_trilho = altura_trilho;
    this->r = r;
    this->g = g;
    this->b = b;
    this->status = status;
    this->movimento = 0;
    this->velocidade=20;
}

void Trem::move()
{
    switch(this->movimento)
    {
        case 0:
            if((this->x + this->velocidade) < (this->x_trilho + this->largura_trilho-this->largura/2))
            {
                this->x+=20;
            }else
            {
                this->x =this->x_trilho + this->largura_trilho-this->largura/2;
                this->movimento = 1;
            }
            break;
        case 1:
            if((this->y + this->velocidade) < (this->y_trilho + this->altura_trilho-this->altura/2))
            {
                this->y+=20;
            }else
            {
                this->y = this->y_trilho + this->altura_trilho;
                this->movimento = 2;
            }
            break;
        case 2:
            if((this->x - this->velocidade) > (this->x_trilho-this->largura/2))
            {
                this->x-=20;
            }else
            {
                this->x =this->x_trilho-this->largura/2;
                this->movimento = 3;
            }
            break;
        case 3:
            if((this->y - this->velocidade) > (this->y_trilho - this->altura/2))
            {
                this->y-=20;
            }else
            {
                this->y = this->y_trilho;
                this->movimento = 0;
            }
            break;


    }


}
