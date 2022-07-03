#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trem.h"
#include "trail.h"

#include <QDebug>
#include <stdio.h>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QTimer>
using namespace std;

Trail trilho(
        250,        /* x */
        250,        /* y */
        256,        /* larg */
        256,        /* alt */
        255,        /* r */
        0,          /* g */
        0           /* b */
    );

Trem trem(
        250,        /* x */
        250,        /* y */
        trilho.x,   /* pos_x do trilho a qual o trem pertence */
        trilho.y,   /* pos_y do trilho a qual o trem pertence */
        25,         /* larg */
        25,         /* alt */
        trilho.largura,/* larg trilho*/
        trilho.altura, /* alt trilho */
        0,          /* r */
        255,        /* g */
        0,          /* b */
        0           /* status */
    );

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->setInterval(200); // 200 milissegundos
    timer->start(); // Se preferir, pode usar start(200) e remover a linha do setInterval
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

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

}

void MainWindow::move()
{
    trem.move();
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}
