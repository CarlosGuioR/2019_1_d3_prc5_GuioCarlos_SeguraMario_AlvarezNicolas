#include <sys/mman.h> //shm_open, mmap
#include <unistd.h> //ftruncate
#include <fcntl.h> //defines the shm_open, mmap
#include <semaphore.h>

const char *name_shm = "sh_mem";
const char *name_sem = "smp";

int main(int argc, char const *argv[])
{

	sem_t *cajas = sem_open(name_shm, O_CREAT);
    sem_t *memoria = sem_open(name_sem, O_CREAT);
    sem_close(cajas);
	shm_unlink(name_shm);
	sem_close(memoria);
	shm_unlink(name_sem);
	shm_unlink("banco");

	return 0;
}