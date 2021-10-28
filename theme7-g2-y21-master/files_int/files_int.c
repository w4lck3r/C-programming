#include "files_int.h"

/*  La file vide :  suivant NULL */

ififo_s *ififo_new(){

    ififo_node_s *newnoeud = NULL;
    ififo_s *files = malloc(sizeof(*files));

    if(files == NULL){
        return NULL;
    }

    files -> suivant = newnoeud;
    files -> dernier = newnoeud;

    return files;
}


int ififo_is_empty(struct ififo_s *f){

    return ((f -> suivant == NULL) && (f -> dernier == NULL));
}

int ififo_enqueue(struct ififo_s *f, int nb){

    ififo_node_s *new = malloc(sizeof(*new));

    if (f == NULL || new == NULL){
        return -1;
    }

    new->nombre = nb;

    if (ififo_is_empty(f)){
        f -> suivant = new;
        f -> dernier = new;
    }
    else{
        f -> dernier -> noeud = new;
        f -> dernier = new;
    }

    new -> noeud = NULL;
    return 0;
}


int ififo_dequeue(struct ififo_s *f, int *nb){

    if (ififo_is_empty(f)){
        return -1;
    }

    ififo_node_s *new = f -> suivant;

    if (f -> suivant == f -> dernier){
        ififo_node_s *new2 = NULL;
        
        *nb = f -> suivant -> nombre;
        f -> suivant = f -> dernier = new2;
    }
    else {
        *nb = new -> nombre;
        f -> suivant = new -> noeud;
    }

    free(new);
    
    return 0;
}


int ififo_head(const struct ififo_s *f){

    return f -> suivant -> nombre;
}


int ififo_apply(struct ififo_s *f, func_t *fn){

    ififo_node_s *apply = f -> dernier;

    while (apply != NULL){
        fn(apply -> nombre);
        apply = apply -> noeud;
    }

    return 0;
}


void ififo_del(struct ififo_s *f){

    ififo_node_s *new = f -> suivant;
    ififo_node_s *del;


    while(new != NULL){
        del = new;
        new = new -> noeud;
        free(del);
    }
    new = NULL;
    free(f);
}

void print_int(int i){
    printf("%d ← ", i);
}

void test_fifo_int(){
    ififo_s *fifo;
    int i;

    fifo = ififo_new();

    ififo_enqueue(fifo, 12); /* → 12 → */
    ififo_enqueue(fifo, 13); /* → 13 → 12 → */

    ififo_apply(fifo, print_int);
    putchar('\n');

    ififo_enqueue(fifo, 14); /* → 14 → 13 → 12 → */
    ififo_dequeue(fifo, &i); /* 12 & → 14 → 13 → */

    printf("%d \n", i);
    ififo_apply(fifo, print_int);
    putchar('\n');

    ififo_dequeue(fifo, &i); /* 13 & → 14 → */
    ififo_dequeue(fifo, &i); /* 14 & → → */
    ififo_apply(fifo, print_int);
    putchar('\n');

    ififo_del(fifo);
}

int main(){
    test_fifo_int();
    return 0;
}