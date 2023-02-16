#include <stdlib.h>
#include <stdio.h>

struct { //los arreglos son estáticos 
    int n;
    int *head;
    int ocupados;
} typedef dinarray;

void init(dinarray *v){

    // dinarray v;
    v->n = 1;
    v->ocupados = 0;
    v->head = (int*) malloc(sizeof(int)*v->n);
    // return v;

}

void printdinarray(dinarray v){

    for(int i = 0; i < v.ocupados; i++){
        printf("%p: %d, ", v.head + (i*sizeof(int)), *(v.head + (i*sizeof(int))));
    }
    printf("\n\n\n");

}

void push(dinarray *v, int x){

    *(v->head + (v->ocupados)*sizeof(int)) = x;
    v->ocupados++;

    if(v->n == v->ocupados){
        dinarray u;
        u.head = v->head;

        v->head = (int*) malloc(v->n*2*sizeof(int));
        v->n = v->n*2;
        for(int i=0; i < v->ocupados; i++){
            *(v->head + i*sizeof(int)) = *(u.head + i*sizeof(int));
        }
        free(u.head);
    }  

}


void pop(dinarray *v){
    v->ocupados -= 1;

    if(v->ocupados == v->n/2){
        dinarray u;
        u.head = v->head;

        v->head = (int*) malloc(((int)v->n/2)*sizeof(int));
        v->n = v->n/2;
        for(int i=0; i < v->ocupados; i++){
            *(v->head + i*sizeof(int)) = *(u.head + i*sizeof(int));
        }

        // free(u.head);
    }

}


int main(){

    dinarray v,u;
    init(&v);
    push(&v,27);
    push(&v,29);
    push(&v,25);
    push(&v,27);
    push(&v,28);
    printdinarray(v);
    pop(&v);
    pop(&v);
    pop(&v);
    pop(&v);
    printdinarray(v);


    /* v = push(v,27);
    v = push(v,28);
    v = push(v,28);
    v = push(v,28); */

    return 0;

}