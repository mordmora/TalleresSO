#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"algorythms.h"

#define _POSIX_TIMERS
#define _REENANT

struct timespec start, end;

int getMode(int *array, int size){
    int max_count = 0;
    int mode = array[0];
    int current_count;

    

    for(int i = 0; i < size; ){
        current_count = 1;
        for(int j = i + 1; j < size; j++){
            if(array[i] == array[j]){
                current_count++;
            } else {
                break;
            }
        }

        if(current_count > max_count){
            max_count = current_count;
            mode = array[i];
        }
        i+=current_count;
    }
    printf("cantidad de repeticiones: %d\n",max_count);
    return mode;
}


int main(int argc, char* argv[]){
    FILE* f;
    f = fopen(argv[1], "r");
    int size;
    int *array = NULL;
    long int sum = 0;
    double elapsed_read, elapsed_sum;

    f = fopen(argv[1], "r");

    if(f == NULL){
        printf("Archivo no encontrado\n");
        exit(1);
    }

    clock_gettime(CLOCK_REALTIME, &start); //tiempo de lectura

    fscanf(f, "%d", &size);
    array = (int*)malloc(size * sizeof(int));

    for(int i = 0; i < size; i++){
        fscanf(f, "%d", &array[i]);
    }

    clock_gettime(CLOCK_REALTIME, &end);

    elapsed_read = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/1e9);

    clock_gettime(CLOCK_REALTIME, &start); //tiempo de suma

    for(int i = 0; i < size; i++){
        sum += array[i];
    }

    clock_gettime(CLOCK_REALTIME, &end);
    
    elapsed_sum = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/1e9);
   
    quicksort (array, 0, size-1);

//    for(int i = 0; i < size; i++){
//	printf("%d\n", array[i]);
//    }
    //printf("before mode function");
    printf("moda: %d\n", getMode(array, size));
    printf("Sum = %ld\n", sum);
    printf("Sum time: %lf seg\n", elapsed_sum);
    printf("Read time: %lf seg\n", elapsed_read);
    return 0;
}
