#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <QPixmap>
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <pthread.h>
#include <semaphore.h>

const char *name_shm = "sh_mem";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/carlos/Escritorio/USTA/Digitales3/Lab5/Banco/img.png");
    ui->img1->setPixmap(pix);
    ui->img2->setPixmap(pix);
    ui->img3->setPixmap(pix);
    ui->img4->setPixmap(pix);
    ui->img5->setPixmap(pix);
    ui->img6->setPixmap(pix);
    ui->img7->setPixmap(pix);
    ui->img8->setPixmap(pix);
    ui->img9->setPixmap(pix);
    ui->img10->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    sem_close(cajas);
    shm_unlink(name_shm);
    shm_unlink("banco");
    delete ui;
}

void MainWindow::inicializar(){


    cajas = sem_open(name_shm, O_CREAT, 0644, num_cajas);

    ui->img1->setVisible(false);
    ui->img2->setVisible(false);
    ui->img3->setVisible(false);
    ui->img4->setVisible(false);
    ui->img5->setVisible(false);
    ui->img6->setVisible(false);
    ui->img7->setVisible(false);
    ui->img8->setVisible(false);
    ui->img9->setVisible(false);
    ui->img10->setVisible(false);
    ui->n1->setVisible(false);
    ui->id1->setVisible(false);
    ui->n2->setVisible(false);
    ui->id2->setVisible(false);
    ui->n3->setVisible(false);
    ui->id3->setVisible(false);
    ui->n4->setVisible(false);
    ui->id4->setVisible(false);
    ui->n5->setVisible(false);
    ui->id5->setVisible(false);
    ui->n6->setVisible(false);
    ui->id6->setVisible(false);
    ui->n7->setVisible(false);
    ui->id7->setVisible(false);
    ui->n8->setVisible(false);
    ui->id8->setVisible(false);
    ui->n9->setVisible(false);
    ui->id9->setVisible(false);
    ui->n10->setVisible(false);
    ui->id10->setVisible(false);

    //printf("%d \n",num_cajas);
   // QString a=QString::number(num_cajas);

    if(num_cajas==1){
        ui->img1->setVisible(false);
        ui->img1->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
    }else if(num_cajas==2){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
    }else if(num_cajas==3){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
    }else if(num_cajas==4){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
    }else if(num_cajas==5){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
    }else if(num_cajas==6){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->img6->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
        ui->n6->setVisible(true);
        ui->id6->setVisible(true);
    }else if(num_cajas==7){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->img6->setVisible(true);
        ui->img7->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
        ui->n6->setVisible(true);
        ui->id6->setVisible(true);
        ui->n7->setVisible(true);
        ui->id7->setVisible(true);
    }else if(num_cajas==8){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->img6->setVisible(true);
        ui->img7->setVisible(true);
        ui->img8->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
        ui->n6->setVisible(true);
        ui->id6->setVisible(true);
        ui->n7->setVisible(true);
        ui->id7->setVisible(true);
        ui->n8->setVisible(true);
        ui->id8->setVisible(true);
    }else if(num_cajas==9){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->img6->setVisible(true);
        ui->img7->setVisible(true);
        ui->img8->setVisible(true);
        ui->img9->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
        ui->n6->setVisible(true);
        ui->id6->setVisible(true);
        ui->n7->setVisible(true);
        ui->id7->setVisible(true);
        ui->n8->setVisible(true);
        ui->id8->setVisible(true);
        ui->n9->setVisible(true);
        ui->id9->setVisible(true);
    }else if(num_cajas==10){
        ui->img1->setVisible(true);
        ui->img2->setVisible(true);
        ui->img3->setVisible(true);
        ui->img4->setVisible(true);
        ui->img5->setVisible(true);
        ui->img6->setVisible(true);
        ui->img7->setVisible(true);
        ui->img8->setVisible(true);
        ui->img9->setVisible(true);
        ui->img10->setVisible(true);
        ui->n1->setVisible(true);
        ui->id1->setVisible(true);
        ui->n2->setVisible(true);
        ui->id2->setVisible(true);
        ui->n3->setVisible(true);
        ui->id3->setVisible(true);
        ui->n4->setVisible(true);
        ui->id4->setVisible(true);
        ui->n5->setVisible(true);
        ui->id5->setVisible(true);
        ui->n6->setVisible(true);
        ui->id6->setVisible(true);
        ui->n7->setVisible(true);
        ui->id7->setVisible(true);
        ui->n8->setVisible(true);
        ui->id8->setVisible(true);
        ui->n9->setVisible(true);
        ui->id9->setVisible(true);
        ui->n10->setVisible(true);
        ui->id10->setVisible(true);
    }

}


void MainWindow::mostrar(char *nombre, QString cedula, int caja){

    if(caja==0){
        ui->n1->setText(nombre);
        ui->id1->setText(cedula);
    }else if(caja==1){
        ui->n2->setText(nombre);
        ui->id2->setText(cedula);
    }else if(caja==2){
        ui->n3->setText(nombre);
        ui->id3->setText(cedula);
    }else if(caja==3){
        ui->n4->setText(nombre);
        ui->id4->setText(cedula);
    }else if(caja==4){
        ui->n5->setText(nombre);
        ui->id5->setText(cedula);
    }else if(caja==5){
        ui->n6->setText(nombre);
        ui->id6->setText(cedula);
    }else if(caja==6){
        ui->n7->setText(nombre);
        ui->id7->setText(cedula);
    }else if(caja==7){
        ui->n8->setText(nombre);
        ui->id8->setText(cedula);
    }else if(caja==8){
        ui->n9->setText(nombre);
        ui->id9->setText(cedula);
    }else if(caja==9){
        ui->n10->setText(nombre);
        ui->id10->setText(cedula);
    }
}
