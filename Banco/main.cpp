#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <semaphore.h>
#include <cstdlib>

#define SIZE 300

const char *name_sem = "smp";


void *proceso(void *param);

typedef struct{//creamos una estructura la cual tendra los items de la memoria compartida
    int bandera1;
    int bandera2;
    int num_cajas;
    char nombre[81];
    int cedula;
    int caja_actual;
}item;

int shm_fd=0;
item *datos_cliente;
void *ptr;
int cajas[10]={0,0,0,0,0,0,0,0,0,0};

MainWindow *w;

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    w = new MainWindow();

    w->num_cajas = atoi(argv[1]);
    w->inicializar();
    w->show();


    //w.proceso();


    shm_fd = shm_open("banco", O_CREAT| O_RDWR, 0666);//creamos la memoria compartida
    ftruncate(shm_fd, SIZE);//reservamos un tamaño SIZE para la memoria
    ptr = mmap(0, SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, shm_fd, 0);
    datos_cliente = (item*)ptr;

    //sem_t *cajas = sem_open(name_shm, O_CREAT, 0600, w->num_cajas);
    sem_t *memoria = sem_open(name_sem, O_CREAT, 0644, 1);

    datos_cliente->bandera1=0;
    datos_cliente->bandera2=0;
    datos_cliente->num_cajas=w->num_cajas;
    printf("ere\n");

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, proceso, NULL);

    return a.exec();
}

void *proceso(void *param){

//    while(datos_cliente->bandera1==0){

//    }
//    printf("34");
//    printf("%s %d\n",datos_cliente->nombre, datos_cliente->cedula);
//    QString a1=QString::number(datos_cliente->cedula);
//    w->mostrar(datos_cliente->nombre,a1);

//    while(datos_cliente->bandera1==0){

//    }
//    a1=QString::number(0);
//    w->mostrar("vacio",a1);

    QString a1;
    int conta=0;
    while(true){

        if(datos_cliente->bandera1==1){
            for(int i=0;i<10;i++){
                if(cajas[i]==0){
                    cajas[i]=1;
                    datos_cliente->caja_actual=i;
                    conta=i;
                    i=10;
                }
            }
            usleep(100);
            a1=QString::number(datos_cliente->cedula);
            w->mostrar(datos_cliente->nombre,a1,conta);
            conta++;

        }else if(datos_cliente->bandera2==1){
            cajas[datos_cliente->caja_actual]=0;
            a1=QString::number(0);
            w->mostrar("vacio",a1,datos_cliente->caja_actual);
            datos_cliente->bandera2=0;
        }
    }

    return 0;
}

