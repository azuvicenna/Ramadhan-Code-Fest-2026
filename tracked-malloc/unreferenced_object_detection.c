#include "stdlib.h"
#include <stdio.h>


struct object {

    void * void_pointer;

    int marked;

};


static struct object object_registry[10];

static int registry_count = 0;


void * tracked_malloc(size_t bytes_size) {

    void * allocated_memory = (void *)malloc(bytes_size);

    object_registry[registry_count].void_pointer = allocated_memory;

    object_registry[registry_count].marked = 0;

    registry_count++;

    free(allocated_memory);
    allocated_memory = NULL;

}


int main() {

    int * tracked_pointer1 = (int *)tracked_malloc(sizeof(int));
    int * tracked_pointer2;

    return 0;

}
