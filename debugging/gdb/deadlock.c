#include <pthread.h>
#include <stdio.h>
 
static pthread_mutex_t first_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t second_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t ready_to_lock = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t cond_mutex = PTHREAD_MUTEX_INITIALIZER;
 
void *second_thread(void *thrdata)
{   
    pthread_mutex_lock(&cond_mutex);
    pthread_mutex_lock(&second_lock);
    pthread_cond_signal(&ready_to_lock);    
    pthread_mutex_unlock(&cond_mutex);
    fprintf(stderr, "about to deadlock\n");
    pthread_mutex_lock(&first_lock);
    pthread_exit(NULL);
}   
 
void *first_thread(void *thrdata)
{
    pthread_t thread2;
    pthread_mutex_lock(&first_lock);
    pthread_mutex_lock(&cond_mutex);
    int err = pthread_create(&thread2, NULL, second_thread, NULL);
    if (err) {
        perror("pthread_create");
    } else {
        pthread_cond_wait(&ready_to_lock, &cond_mutex);
        pthread_mutex_lock(&second_lock);
    }
    pthread_exit(NULL);
}
 
int
main(int argc, char **argv)
{
    pthread_t thread1;
    int err = pthread_create(&thread1, NULL, first_thread, NULL);
    if (err) {
        perror("pthread_create");
    }
    pthread_exit(NULL);
}
