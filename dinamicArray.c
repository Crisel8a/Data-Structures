#include <stdlib.h>
#include <stdio.h>

struct { //los arreglos son estáticos y estériles
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
        printf(" %d, ", *(v.head + (i*sizeof(int))));
    }

}

dinarray push(dinarray v, int x){

    *(v.head+ v.ocupados*sizeof(int)) = x;
    v.ocupados += 1;

    if (v.n == v.ocupados){
        dinarray u;
        u.n = 2*v.n;
        u.ocupados = v.ocupados;
        u.head = (int*) malloc(sizeof(int)*u.n);

        for(int i = 0; i < u.ocupados; i++){
            *(u.head+ i*sizeof(int)) = *(v.head+ i*sizeof(int));
        }

        free(v.head);
        return u;
    }

    return v;

}


int main(){

    dinarray v,u;
    v = init();
    u = init();

    printdinarray(v);
    v = push(v,27);
    printdinarray(v);
    printf("\n\n");
    v = push(v,28);
    v = push(v,28);
    v = push(v,28);
    v = push(v,28);
    v = push(v,28);
    printdinarray(v);

    return 0;

}