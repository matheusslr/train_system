#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trem.h"
#include "trail.h"
#include <semaphore.h>

#include <QDebug>
#include <stdio.h>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QTimer>
#include <QThread>

#include <pthread.h>
#include <semaphore.h>
using namespace std;

Trail trilho(
        175,        /* x */
        50,        /* y */
        100,        /* larg */
        100,        /* alt */
        255,        /* r */
        0,          /* g */
        0           /* b */
        );

Trem trem(
        trilho.x,        /* x */
        trilho.y,        /* y */
        trilho.x,   /* pos_x do trilho a qual o trem pertence */
        trilho.y,   /* pos_y do trilho a qual o trem pertence */
        25,         /* larg */
        25,         /* alt */
        trilho.largura,/* larg trilho*/
        trilho.altura, /* alt trilho */
        255,        /* r */
        0,          /* g */
        0,          /* b */
        0           /* status */
        );

Trail trilho2(
        300,         /* x */
        50,         /* y */
        100,        /* larg */
        100,        /* alt */
        0,          /* r */
        255,        /* g */
        0           /* b */
        );

Trem trem2(
        trilho2.x,        /* x */
        trilho2.y,        /* y */
        trilho2.x,   /* pos_x do trilho a qual o trem pertence */
        trilho2.y,   /* pos_y do trilho a qual o trem pertence */
        25,         /* larg */
        25,         /* alt */
        trilho2.largura,/* larg trilho*/
        trilho2.altura, /* alt trilho */
        0,          /* r */
        255,        /* g */
        0,          /* b */
        0           /* status */
        );

Trail trilho3(
        175,         /* x */
        175,         /* y */
        100,        /* larg */
        100,        /* alt */
        0,          /* r */
        0,          /* g */
        255         /* b */
        );

Trem trem3(
        trilho3.x,        /* x */
        trilho3.y,        /* y */
        trilho3.x,   /* pos_x do trilho a qual o trem pertence */
        trilho3.y,   /* pos_y do trilho a qual o trem pertence */
        25,         /* larg */
        25,         /* alt */
        trilho3.largura,/* larg trilho*/
        trilho3.altura, /* alt trilho */
        0,          /* r */
        0,          /* g */
        255,        /* b */
        0           /* status */
        );

Trail trilho4(
        300,         /* x */
        175,         /* y */
        100,        /* larg */
        100,        /* alt */
        255,        /* r */
        255,        /* g */
        0           /* b */
        );

Trem trem4(
        trilho4.x,        /* x */
        trilho4.y,        /* y */
        trilho4.x,   /* pos_x do trilho a qual o trem pertence */
        trilho4.y,   /* pos_y do trilho a qual o trem pertence */
        25,         /* larg */
        25,         /* alt */
        trilho4.largura,/* larg trilho*/
        trilho4.altura, /* alt trilho */
        255,        /* r */
        255,        /* g */
        0,          /* b */
        0           /* status */
        );



sem_t semL3;
sem_t semL4;
sem_t semL7;
sem_t semL9;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->setInterval(20); // 200 milissegundos
    timer->start(); // Se preferir, pode usar start(200) e remover a linha do setInterval

    sem_init(&semL3, 0, 1);
    sem_init(&semL4, 0, 1);
    sem_init(&semL7, 0, 1);
    sem_init(&semL9, 0, 1);
    pthread_t thread1,thread2,thread3,thread4;
    pthread_create(&thread1, NULL, MainWindow::trem_1,(void*)this);
    pthread_create(&thread2, NULL, MainWindow::trem_2,(void*)this);
    pthread_create(&thread3, NULL, MainWindow::trem_3,(void*)this);
    pthread_create(&thread4, NULL, MainWindow::trem_4,(void*)this);

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    //trem 1
    pen.setWidth(3);
    pen.setColor(QColor(trilho.r,trilho.g,trilho.b));
    painter.setPen(pen);
    painter.drawRect(QRect(trilho.x, trilho.y, trilho.largura, trilho.altura));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(trem.r,trem.g,trem.b));
    painter.setBrush(brush);
    pen.setColor(QColor(trem.r,trem.g,trem.b));
    painter.setPen(pen);
    painter.drawRect(trem.x,trem.y-trem.altura/2,trem.largura,trem.altura);      // pode andar de x ate x+larg

    //trem 2
    painter.setBrush(Qt::NoBrush);
    pen.setColor(QColor(trilho2.r,trilho2.g,trilho2.b));
    painter.setPen(pen);
    painter.drawRect(QRect(trilho2.x, trilho2.y, trilho2.largura, trilho2.altura));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(trem2.r,trem2.g,trem2.b));
    painter.setBrush(brush);
    pen.setColor(QColor(trem2.r,trem2.g,trem2.b));
    painter.setPen(pen);
    painter.drawRect(trem2.x,trem2.y-trem2.altura/2,trem2.largura,trem2.altura);      // pode andar de x ate x+larg

    //trem 3
    painter.setBrush(Qt::NoBrush);
    pen.setColor(QColor(trilho3.r,trilho3.g,trilho3.b));
    painter.setPen(pen);
    painter.drawRect(QRect(trilho3.x, trilho3.y, trilho3.largura, trilho3.altura));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(trem3.r,trem3.g,trem3.b));
    painter.setBrush(brush);
    pen.setColor(QColor(trem3.r,trem3.g,trem3.b));
    painter.setPen(pen);
    painter.drawRect(trem3.x,trem3.y-trem3.altura/2,trem3.largura,trem3.altura);      // pode andar de x ate x+larg

    //trem 4
    painter.setBrush(Qt::NoBrush);
    pen.setColor(QColor(trilho4.r,trilho4.g,trilho4.b));
    painter.setPen(pen);
    painter.drawRect(QRect(trilho4.x, trilho4.y, trilho4.largura, trilho4.altura));

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(trem4.r,trem4.g,trem4.b));
    painter.setBrush(brush);
    pen.setColor(QColor(trem4.r,trem4.g,trem4.b));
    painter.setPen(pen);
    painter.drawRect(trem4.x,trem4.y-trem4.altura/2,trem4.largura,trem4.altura);      // pode andar de x ate x+larg

}

void *MainWindow::trem_1(void *arg)
{

    while(1)
    {

        if(trem.getTrilho()==1)
        {

            sem_wait(&semL3);

            while(1)
            {
                trem.move();
                if(trem.getTrilho()==2)
                {
                    break;
                }

                QThread::msleep(20);

            }

            sem_post(&semL3);

        }else if(trem.getTrilho()==2)
        {
            sem_wait(&semL4);
            qDebug()<<"regiao critica l4 1"<<endl;

            while(1)
            {
                trem.move();
                if(trem.getTrilho()==3) break;
                QThread::msleep(20);
            }
            sem_post(&semL4);

        }else
        {

            trem.move();
            QThread::msleep(20);
        }
    }

}

void *MainWindow::trem_2(void *arg)
{
    while(1)
    {
        if(trem2.getTrilho()==3)
        {
            sem_wait(&semL3);
            while(1)
            {
                trem2.move();
                qDebug()<<"regiao critica L3 2"<<endl;
                if(trem2.getTrilho()==0)
                {
                    break;
                }
                QThread::msleep(20);

            }
            sem_post(&semL3);
        }else if(trem2.getTrilho()==2)
        {
            sem_wait(&semL7);
            while(1)
            {
                trem2.move();
                qDebug()<<"regiao critica L7 2"<<endl;
                if(trem2.getTrilho()==3)
                {
                    break;
                }
                QThread::msleep(20);

            }
            sem_post(&semL7);
        }
        else
        {
            trem2.move();
            QThread::msleep(20);
        }
    }
}
void *MainWindow::trem_3(void *arg)
{
    while(1)
    {
        if(trem3.getTrilho()==0)
        {
            sem_wait(&semL4);
            qDebug()<<"regiao critica l4 3"<<endl;
            while(1)
            {
                trem3.move();
                if(trem3.getTrilho()==1)
                {
                    break;
                }
                QThread::msleep(20);

            }
            sem_post(&semL4);
        }else if(trem3.getTrilho()==1)
        {
            sem_wait(&semL9);
            qDebug() << "região critica l9 3" << endl;
            while(1)
            {
                trem3.move();
                if(trem3.getTrilho()==2)
                {
                    break;
                }
                QThread::msleep(20);
            }
            sem_post(&semL9);
        }
        else
        {
            trem3.move();
            QThread::msleep(20);
        }
    }
}
void *MainWindow::trem_4(void *arg)
{
    qDebug()<<"okay"<<endl;
    while(1)
    {
        if(trem4.getTrilho()==3)
        {
            sem_wait(&semL9);
            qDebug() << "regiao critica l9 4" << endl;
            while(1)
            {
                trem4.move();
                if(trem4.getTrilho()==0)
                {
                    break;
                }
                QThread::msleep(20);
            }
            sem_post(&semL9);
        }else if(trem4.getTrilho()==0)
        {
            sem_wait(&semL7);
            qDebug() << "regiao critica l7 4" << endl;
            while(1)
            {
                trem4.move();
                if(trem4.getTrilho()==1)
                {
                    break;
                }
                QThread::msleep(20);
            }
            sem_post(&semL7);
        }
        else
        {
            trem4.move();
            QThread::msleep(20);
        }
    }
}

void MainWindow::move()
{
    int vel = ui->sliderVel1->value();
    trem.setVel(vel);

    int vel2 = ui->sliderVel2->value();
    trem2.setVel(vel2);

    int vel3 = ui->sliderVel3->value();
    trem3.setVel(vel3);

    int vel4 = ui->sliderVel4->value();
    trem4.setVel(vel4);

    repaint();

}

MainWindow::~MainWindow()
{
    delete ui;
}
