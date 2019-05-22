#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap


typedef struct{//creamos una estructura la cual tendra los items de la memoria compartida
	int bandera1;
    int bandera2;
	char nombre[81];
    int cedula;
}item;



void main(int argc, char const *argv[])
{
	int shm_fd;
	void *ptr;
	item *datos_cliente;

	shm_fd = shm_open("memoria",O_RDWR, 0666);
	ptr = mmap(0, SIZE, PROT_WRITE|PROT_READ, MAP_SHARED, shm_fd, 0);
	datos_cliente = (item*)ptr;

	while(true){

		if(datos_cliente->bandera1==1){
			char *nombre;
			int cedula;

			strcpy(nombre,argv[1]);
			cedula = atoi(argv[2]);

			
			break;
		}	

	}
	

	return 0;
}