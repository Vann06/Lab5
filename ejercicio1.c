#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000 

int main(){
    long long suma = 0;
    double start_time, end_time;

    start_time = omp_get_wtime;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 1; i <= N; i++){
        suma +=1;
    }

    end_time = omp_get_wtime;

    printf("Suma: %d \n",suma );
    printf("Tiempo de ejecucion en %f segundos\n", end_time - start_time);

    return 0;
}