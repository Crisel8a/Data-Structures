#include <stdlib.h>
#include <stdio.h>

struct { //los arreglos son estáticos 
    int n;
    int *head;
} typedef array;

array init(int n){

    array v;

    v.n = n;
    v.head = (int*) malloc(v.n*sizeof(int)); // int* es un tipo de dato para apuntadores enteros 

    return v;

}

int get(array v, int p){

    return *(v.head + p*sizeof(int));

}

void printarray(array v){

    printf("[");

    for(int i=0; i<=v.n-1; i++){
        printf(" %d, ", *(v.head + (i*sizeof(int)))); //* lo que almacena la direccion de memoria 
    }

    printf("]");
}

void insert(array v, int p, int x){

    *(v.head + p*sizeof(int)) = x;  
}

int main(){

    array v = init(3); 
    printarray(v);
    printf("\n%d", get(v,1));
    insert(v,1,27);
    printarray(v);

    return 0;
}

