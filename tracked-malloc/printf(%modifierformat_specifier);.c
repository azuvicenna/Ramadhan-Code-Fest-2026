#include "stdlib.h"
#include <stdio.h>


void * tracked_malloc(size_t bytes_size) {

    /*
    int    is a      sign integer; 4 bytes on x64
    size_t is an unsigned integer; 8 bytes on x64

    int            is general-purpose integer arithmetic
    size_t purpose is to represents sizes, array indices, and results of sizeof
    */

    printf("sizeof(int   )   signed integer = %ld bytes                                 \n", sizeof(int   ));
    printf("sizeof(size_t) unsigned integer = %ld bytes with %%ld print format specifier\n", sizeof(size_t));
    printf("sizeof(size_t) unsigned integer = %zu bytes with %%zu print format specifier\n", sizeof(size_t));

    /*
    printf("%modifier:format_specifier");
    printf("%size_t:unsigned");
    printf("%zu");
    */

    void * allocated_memory = (void *)malloc(bytes_size);

    free(allocated_memory);
    allocated_memory = NULL;

}


int main() {

    int * a = (int *)tracked_malloc(sizeof(int));

    return 0;

}
