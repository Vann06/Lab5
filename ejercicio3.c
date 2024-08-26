#include <stdio.h>
#include <omp.h>

// Modificación de dos variables en paralelo usando 
//#pragma omp parallel for

int main() {

    int variable1 = 0, variable2 = 0;

    // Usando shared para variable1 y private para variable2
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < 10; i++) {
        variable1 += i; //variable compartida
        variable2 = i * 2; //variable privada
        printf("Iteración %d - variable1: %d, variable2: %d\n", i, variable1, variable2);
    }

    return 0;
}