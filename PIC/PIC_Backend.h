#pragma once
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "PIC_Common.h"
//dlerror takes the handle returned by dlopen.. 
void* dlopen(char*, int);
void* dlsym(void*, char*);
int   dlerror(void*);


