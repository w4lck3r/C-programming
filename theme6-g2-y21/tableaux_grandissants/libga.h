#ifndef LIBGA_H
#define LIBGA_H

struct ga_s {
    unsigned int ga_size;  /* number of allocate elements  */
    int *ga_elements;  /* elements "int" */
};

int ga_set(struct ga_s *ga, unsigned int index, int val); //set an element in index with a value
int ga_get(struct ga_s *ga, unsigned int index, int *val); //get an element in index with a value
int ga_new(struct ga_s *ga); //make an element
int ga_del(struct ga_s *ga); //del an element

#endif
