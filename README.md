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



# Conclusiones:
	
- El banco no tiene limite de clientes inscritos mas alla de la capacidad del computador, al ser manejado con listas en python proveen una facilidad de tratamiento de datos muy grande

- La comunicacion entre QT y python es mas facil (concepto propio del grupo) que la comunicacion entre QT y C++, la forma de escribir las funciones y de realizar las conexiones es mas intuitiva y facil.

- La plataforma QT es una gran herramienta grafica, aunque no exploramos todas las posibilidades que esta ofrece, si se observo que es muy amplia y robusta.

- La comunicacion por tuberias entre estos dos lenguajes de programacion es un poco complicada debido al cambio de sintaxis, sin embargo es muy util y entendible conforme a la experiencia y al uso de esta.


	




















