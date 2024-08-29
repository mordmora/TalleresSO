#include <bits/time.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
//#include"algorythms.h"

#define _POSIX_TIMERS
#define _REENANT
#define MAX_HASHT_SIZE 10000
struct timespec start, end;


void getMaxFreq(int* array, int size){

  int* hashT = (int*)malloc(sizeof(int)*MAX_HASHT_SIZE);
  memset(hashT, 0, sizeof(int) * MAX_HASHT_SIZE);
  int most_freq_e = array[0];
  int freq = 0;
  double time_elapsed = 0;


  clock_gettime(CLOCK_REALTIME, &start);

  for(int i = 0; i < size; i++){
    hashT[array[i]]++;
    if(hashT[array[i]] > freq){
      freq = hashT[array[i]];
      most_freq_e = array[i];
    }
  }

  clock_gettime(CLOCK_REALTIME, &end);


  time_elapsed = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/1e9);

  printf("most common value = %d\n", most_freq_e);
  printf("frequency = %d\n", freq);
  printf("frequency estimation = %f\n seg", time_elapsed);
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
    getMaxFreq(array, size); 
    elapsed_sum = (end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec)/1e9);
   
    printf("Sum = %ld\n", sum);
    printf("Sum time: %lf seg\n", elapsed_sum);
    printf("Read time: %lf seg\n", elapsed_read);
    return 0;
}
