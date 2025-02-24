#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
typedef struct vector{
  char* bytes;
  int vector_size;
  int max_size;
}vector;

void init_vector(vector* v,int vector_allocation_size){
  v->max_size = vector_allocation_size;
  v->vector_size = 0;
  v->bytes = (char *)malloc(v->vector_size);
  return;
}

void push_vector(vector* v,char byte){
  if (v->vector_size >= v->max_size-1){
    v->bytes = (char *) realloc((void*)v->bytes,v->max_size*2);
    v->max_size *=2;
  } 
  v->bytes[v->vector_size] = byte;
  v->vector_size++;
  return;
}
void pop_vector(vector* v){
}
#endif
