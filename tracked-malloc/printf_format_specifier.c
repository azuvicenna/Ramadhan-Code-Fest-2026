#include "stdio.h"
#include <stdlib.h>


int main() {

    size_t * size_t_is_unsigned_integer_of_8bytes = calloc(1, sizeof * size_t_is_unsigned_integer_of_8bytes);

    /*void * calloc(size_t number_of_bytes_size, size_t bytes_size);*/
    void * (* contiguous_sequence_memory_allocation)(size_t, size_t) = calloc;

    contiguous_sequence_memory_allocation = calloc(1, sizeof * size_t_is_unsigned_integer_of_8bytes);
    /*
    printf format specifier %d and %i are act interchangeable/identically (both print a signed decimal integer)
 
    the critical difference is in scanf :
    scanf  format specifier %d interprets input only as base-10
    scanf  format specifier %i interprets input as decimal     base 10
                                                   hexadecimal base 16 with 0x prefix
                                                   octal       base  8 with 0  prefix

    scanf examples :
    input "010"  : %d reads 10, %i reads 8 (octal)
    input "0x10" : %d stops at 'x' and reads 0, %i reads 16 decimal

    usage :
    use %d for strict decimal input
    use %i if you need to allow users to input octal or hexadecimal or decimal values
    */

    scanf("%i", size_t_is_unsigned_integer_of_8bytes);

    printf("%i\n", size_t_is_unsigned_integer_of_8bytes);

    free(contiguous_sequence_memory_allocation);
    contiguous_sequence_memory_allocation = NULL;
    return 0;

}
