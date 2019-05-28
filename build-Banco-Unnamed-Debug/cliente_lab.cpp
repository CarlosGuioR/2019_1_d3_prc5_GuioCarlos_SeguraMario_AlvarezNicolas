#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>

#define SIZE 300
const char *name_shm = "sh_mem";
const char *name_sem = "smp";


typedef struct{//creamos una estructura la cual tendra los items de la memoria compartida
	int bandera1;
	int bandera2;
    int num_cajas;
	char nombre[81];
    int cedula;
    int caja_actual;
}item;



int main(int argc, char** argv)
{

	int shm_fd=0, caja_actual=0;
	void *ptr;
	item *datos_cliente;
	char *nombre;
	srand(time(NULL));


	shm_fd = shm_open("banco",O_RDWR, 0666);
	ptr = mmap(0, SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, shm_fd, 0);
	datos_cliente = (item*)ptr;

    sem_t *cajas = sem_open(name_shm, O_CREAT);
    sem_t *memoria = sem_open(name_sem, O_CREAT);

	printf("aca voy \n");

	sem_wait(cajas);

	printf("aca voy tiririn\n");

	sem_wait(memoria);

	usleep(1000);
	datos_cliente->bandera1=1;
	nombre=argv[1];
	strcpy(datos_cliente->nombre,nombre);
	datos_cliente->cedula = atoi(argv[2]);
	caja_actual=datos_cliente->caja_actual;
	printf("%d %s %d\n",caja_actual,datos_cliente->nombre,datos_cliente->cedula);
	datos_cliente->bandera1=0;
	sem_post(memoria);

	int num = (5+rand()%(15))*1000000;
	printf("Durara %d segundos\n",num/1000000);
	usleep(num);
	sem_wait(memoria);
	datos_cliente->caja_actual=caja_actual;
	datos_cliente->bandera2=1;
	sem_post(memoria);
	sem_post(cajas);

	return 0;
}