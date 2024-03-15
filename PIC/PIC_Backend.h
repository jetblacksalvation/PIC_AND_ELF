#include <stdio.h>

#include <stdint.h>
//dlerror takes the handle returned by dlopen.. 
void* dlopen(char*, int);
void* dlsym(void*, char*);
int   dlerror(void*);


