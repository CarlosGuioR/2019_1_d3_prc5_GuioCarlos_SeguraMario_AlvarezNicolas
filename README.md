# Laboratorio 5 
# Sistemas Digitales III

### Presentado por:

- Carlos Fernando Guio Rodriguez
- Mario Alberto Segura Albarracin
- Nicolas Alzarez Casadiego

# Introduccion:
	
En este progama se busca coordinar y sincronizar lo que serian las cajas disponibles en un banco con la cantidad de clientes entrantes; se realiza una interfaz grafica en QT Creator en donde se muestran el numero de cajas disponibles (entre 1 y 10) y en cada una se muestra si esta disponible o los datos del cliente que esta atendiendo.
Los clientes son un proceso a parte en el que se accede a las cajas en caso de estar disponibles, en caso de no estarlo queda en espera hasta que una de ellas se desocupe. La sincronizacion se hizo mediante semaforos.

# Desarrollo del programa

El funcionamiento del programa se lleva a cabo en dos programas diferentes, el primero que es el del banco en donde se tienen en cuenta todas las funciones de las cajas y el programa del cliente que es donde se obtienen los datos del cliente y los datos respecto a este.

## Banco:

El desarrollo del banco se hizo de la siguiente forma:

![Screenshot](Flujo_banco.png)

Al ejecutar el programa se pide un argumento que es el numero de cajas que se activaran, "`./Banco #`", con este argumento se inicializa la interfaz grafica de del programa. 

![Screenshot](interfaz.png)
(ejemplo con 5 cajas)
 
En este mismo proceso se inicializa el semaforo que se destinara a las cajas, `cajas = sem_open(name_shm, O_CREAT, 0644, num_cajas)` en esta seccion, **num_cajas** es el argumento que se recibe al ejecutar el programa y **name_shm** es el nombre de el semaforo que es "smp".

Despues de esto se crea la memoria compartida con el nombre "banco" y se le asigno la siguiente estructura:

```
typedef struct{

    int bandera1;
    int bandera2;
    int num_cajas;
    char nombre[81];
    int cedula;
    int caja_actual;
}item;
```
Se inicializan las banderas bandera1 y bandera2 con 0 y se le asigna a num_cajas el argumento que se recibio desde la consola; despues de esto se crea un hilo que apunta a una funcion llamada **proceso** en la que se hace todo lo referente a lectura de banderas y mostrar los cambios en la interfaz grafica. Despues de crear el hilo el programa ejecuta la instruccion `return a.exec()` que se encarga de mostrar la interfaz grafica.

En este momento todo lo referente 

```
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
```

# Conclusiones:
	
- No fue posible inicializar los semaforos en la misma seccion de codigo, entre las multiples pruebas que se hicieron, la que mejor resulto fue inicializar un semaforo en la interfas del "mainwindow" y el otro semaforo en el "main".


	




















