#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <semaphore.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int num_cajas;
    sem_t *cajas;
    ~MainWindow();
    void inicializar();
    void proceso();
    void mostrar(char *nombre, QString cedula, int caja);


private slots:
    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
