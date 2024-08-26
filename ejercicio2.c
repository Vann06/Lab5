#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Ejecución de tres funciones diferentes en
// paralelo usando #pragma omp sections

//calcular el factorial de n veces 
void calcular_factorial(int n){
    long long factorial = 1;

    for(int i = 1; i <= n; i++){
        factorial *=i ;
    }

    print("Factorial %d: es %11d\n",n,factorial);
}

//generar fibonacci con n numeros propuestos
void generar_fibonacci(int n){
    long long primero = 0, segundo = 1, next;
    for(int i = 3; i <= n; i++){
        next = primero + segundo;
        printf("%11d",next);
        primero=segundo;
        segundo=next;
    }
    printf("\n");
}

//encontrar el numero max en el arreglo
void max_array(int arr[], int size){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("MAX en el arreglo: %d\n", max)
}

int main(){
    int n = 10;
    int arr[] = {1,3,5,10,8,2,7,4,9};

    #pragma omp parallel sections
    {
        #pragma omp section 
        {
            calcular_factorial(n);
        }
        #pragma omp section
        {
            generar_fibonacci(n);
        }
        #pragma omp section 
        {
            max_array(arr,n);
        }
    }
    retun 0;
}

