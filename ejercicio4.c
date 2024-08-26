#include <stdio.h>
#include <stdlib.h>
#include <omp.h>  

#define N 131072 

/*
 * Cuenta cuántas veces aparece un valor específico ('key') en un arreglo de manera paralela.
 * El número de veces que 'key' aparece en el arreglo.
 */
long count_key_parallel(long Nlen, long *a, long key) {
    long count = 0;

    // Paralelizamos el ciclo for para contar las apariciones de 'key'
    #pragma omp parallel for reduction(+:count)
    for (long i = 0; i < Nlen; i++) {
        if (a[i] == key) count++;
    }

    return count;
}

int main() {
    long a[N], key = 42, nkey = 0, nkey_parallel = 0;

    // Llenamos el arreglo con valores aleatorios
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    
    // Insertamos el valor 'key' en tres posiciones específicas
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;
    
    // Conteo secuencial de 'key' en el arreglo
    nkey = count_key_parallel(N, a, key);
    printf("Numero de veces que 'key' aparece secuencialmente: %ld\n", nkey);

    // Conteo paralelo de 'key' en el arreglo
    nkey_parallel = count_key_parallel(N, a, key);
    printf("Numero de veces que 'key' aparece en paralelo: %ld\n", nkey_parallel);

    return 0;
}