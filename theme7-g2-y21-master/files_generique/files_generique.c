#include "files_generique.h"

#define L 6 //tab length used in the test


gfifo_s *gfifo_new(){

    gfifo_node_s *newnoeud = NULL;
    gfifo_s *files = malloc(sizeof(*files));

    if (files == NULL){
        return NULL;
    }
    files -> suivant = newnoeud;
    files -> dernier = newnoeud;

    return files;
}

int gfifo_del(struct gfifo_s *f){

    gfifo_node_s *del = f -> dernier;

    while (del != NULL){
        free(del);
        f -> dernier = f -> dernier -> noeud;
        del = f->dernier;
    }
    free(f);
    return 0;
}

int gfifo_size(struct gfifo_s *f){

    gfifo_node_s *size = f -> dernier;

    int cpt;
    cpt = 0;

    while (size != NULL){
        cpt++;
        size = size -> noeud;
    }

    return cpt;
}

int gfifo_enqueue(struct gfifo_s *f, void *nb){

    gfifo_node_s *enqueue = malloc(sizeof(*enqueue));

    if (f == NULL || enqueue == NULL){
        return -1;
    }

    enqueue -> nombre = nb;
    enqueue -> noeud = NULL;

    if (f -> suivant == NULL && f -> dernier == NULL){
        f -> dernier = f -> suivant = enqueue;
    }
    else{
        f -> suivant -> noeud = enqueue;
        f -> suivant = enqueue;
    }

    return 0;
}

int gfifo_dequeue(struct gfifo_s *f, void **nb){

    gfifo_node_s *dequeue;

    if (f -> suivant == NULL && f -> dernier == NULL){
        return -1;
    }

    dequeue = f -> dernier;
    (*nb) = dequeue -> nombre;
    f -> dernier = dequeue -> noeud;

    free(dequeue);

    return 0;
}

int gfifo_apply(struct gfifo_s *f, gfunc_t *fn){

    gfifo_node_s *apply = f -> dernier;

    while (apply != NULL){
        fn(apply -> nombre);
        apply = apply -> noeud;
    }

    return 0;
}

void printg_int(void *i){
    printf("→ %d ", *((int *)i));
}

int main(void){

    gfifo_s *gfifo;
    int tab[L] = {1, 3, 4, 9, 16, 20};
    int i;
    void *del;

    gfifo = gfifo_new();

    for (i = 0; i < L; i++){
        gfifo_enqueue(gfifo, &tab[i]);
        gfifo_apply(gfifo, printg_int);
        putchar('\n');
    }

    printf("size : %d\n\n", gfifo_size(gfifo));

    for (i = 0; i < L; i++){
        gfifo_dequeue(gfifo, &deleted);
        printf("delete : %d \n", *(int *)deleted);
        gfifo_apply(gfifo, printg_int);
        putchar('\n');
    }

    gfifo_apply(gfifo, printg_int);
    putchar('\n');
    gfifo_del(gfifo);

    return 0;
}
