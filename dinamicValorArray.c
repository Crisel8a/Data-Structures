#include <stdlib.h>
#include <stdio.h>

struct { //los arreglos son estáticos 
    int n;
    int *head;
    int ocupados;
} typedef dinarray;

dinarray init(){

    dinarray v;
    v.n = 1;
    v.ocupados = 0;
    v.head = (int*) malloc(sizeof(int)*v.n);
    return v;

}

void printdinarray(dinarray v){

    for(int i = 0; i < v.ocupados; i++){
        printf("%p: %d, ", v.head + (i*sizeof(int)), *(v.head + (i*sizeof(int))));
    }

}

dinarray push(dinarray v, int x){
    printf("\n\nV es: con ocupdaos %d  añadiendo %d ", v.ocupados, x);
    printdinarray(v);

    *(v.head+ v.ocupados*sizeof(int)) = x;
    v.ocupados += 1;

    printf("\nElemento añadido: ");
    printdinarray(v);
    if (v.n == v.ocupados){
        dinarray u;
        u.n = 2*v.n;
        u.ocupados = v.ocupados;
        u.head = (int*) malloc(sizeof(int)*u.n);
        printf("\nV despues del malloc: ");
        printdinarray(v);

        memcpy( u.head, v.head, u.n );
/*         for(int i = 0; i < u.ocupados; i++){
            printf("\nIgualando = %p: %d", v.head+ i*sizeof(int), *(v.head+ (i*sizeof(int))));
            *(u.head+ i*sizeof(int)) = *(v.head+ i*sizeof(int));
        } */
        printf("\nREGRESANDO U:");
        printdinarray(u);
       /*  printf("\n\nV es: ");
        printdinarray(v);
        printf("\nU es: ");
        printdinarray(u);
        printf("\n");
        free(v.head); */
        return u;
    }
    printf("\nREGRESANDO V:");
    printdinarray(v);

    return v;

}


int main(){

    dinarray v,u;
    v = init();

    v = push(v,27);
    v = push(v,28);
    v = push(v,28);
    v = push(v,28);

    return 0;

}