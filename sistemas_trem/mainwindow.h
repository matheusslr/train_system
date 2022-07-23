#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    static void* trem_1(void* arg);
    static void* trem_2(void* arg);
    static void* trem_3(void* arg);
    static void* trem_4(void* arg);

    ~MainWindow();
public slots:
    void move();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
