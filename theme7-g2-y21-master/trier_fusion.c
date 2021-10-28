#include "files_int.h"
#include "files_generique.h"
#define X 6

ififo_s *ififo_merge(ififo_s *f1, ififo_s *f2){

    ififo_s *ififo;
    int number;

    ififo = ififo_new();
    while (f1 -> dernier != NULL){
        ififo_dequeue(f1, &number);
        ififo_enqueue(ififo, number);
    }
    while (f2 -> dernier != NULL){
        ififo_dequeue(f2, &number);
        ififo_enqueue(ififo, number);
    }
    ififo_del(f1);
    ififo_del(f2);
    return ififo;
}

gfifo_s *trier(ififo_s *f)
{
    gfifo_s *gfifo = (gfifo_s *) f;
    gfifo_apply(gfifo, printg_int);
    return NULL;
}

int main(void)
{
    int i;
    struct ififo_s *fifo1, *fifo2, *fifoMerge;
    struct gfifo_s *gfifo;

    fifo1 = ififo_new();
    fifo2 = ififo_new();
    gfifo = gfifo_new();
    for (i = 1; i < X + 1; i++){
        ififo_enqueue(fifo1, i);
        ififo_enqueue(fifo2, i + 5);
    }
    puts("F1: ");
    ififo_apply(fifo1, print_int);
    putchar('\n');

    puts("F2: ");
    ififo_apply(fifo2, print_int);
    putchar('\n');

    puts("MERGE: fifo1 , fofo2 ");
    fifoMerge = ififo_merge(fifo1, fifo2);
    ififo_apply(fifoMerge, print_int);
    putchar('\n');

    puts("TRIER: ");
    gfifo = trier(fifoMerge);
    gfifo_apply(gfifo, printg_int);
    putchar('\n');

    return 0;
}