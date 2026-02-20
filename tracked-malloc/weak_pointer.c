#include <stdio.h>
#include "stdlib.h"


struct object {

    struct object_control * pointer_to_struct_object_control;

    int int_value;

};


struct object_control {

    int int_strong;

    int int_weak;

    struct object * pointer_to_struct_object; 

};

struct weak_pointer {struct object_control * struct_object_control;};


struct object * new_object(int int_value) {

    struct object_control * pointer_to_struct_object_control = (struct object_control *)malloc(sizeof * pointer_to_struct_object_control);

    struct object * pointer_to_struct_object                 = (struct object         *)malloc(sizeof * pointer_to_struct_object);

    (* pointer_to_struct_object_control).int_strong = 1;

    (* pointer_to_struct_object_control).int_weak   = 0;

    (* pointer_to_struct_object_control).pointer_to_struct_object = pointer_to_struct_object;

    (* pointer_to_struct_object).pointer_to_struct_object_control = pointer_to_struct_object_control;

    printf("create  object pointer at address %p\n", (void *)pointer_to_struct_object);

    return pointer_to_struct_object;

}


struct weak_pointer new_weak_pointer(struct object * struct_object) {

    struct weak_pointer struct_weak_pointer;

    struct_weak_pointer.struct_object_control = (* struct_object).pointer_to_struct_object_control;

    (* struct_weak_pointer.struct_object_control).int_weak++;

    return struct_weak_pointer;

}


void release_pointer_to_object(struct object * pointer_to_struct_object) {

    struct object_control * pointer_to_struct_object_control = (* pointer_to_struct_object).pointer_to_struct_object_control;

    if (--(* pointer_to_struct_object_control).int_strong == 0) {

        printf("destroy object pointer at address %p\n", (void *)pointer_to_struct_object);

        free(pointer_to_struct_object);

        (* pointer_to_struct_object_control).pointer_to_struct_object = (void *)0;

        if ((* pointer_to_struct_object_control).int_weak == 0) free(pointer_to_struct_object_control);

        free(pointer_to_struct_object_control);

    }

}


struct object * weak_lock(struct weak_pointer * pointer_to_struct_weak_pointer) {








}












int main() {

    /*int_strong = 1*/
    struct object * pointer_to_struct_object = new_object(12);

    /*int_weak = 1*/
    struct weak_pointer struct_weak_pointer = new_weak_pointer(pointer_to_struct_object);

    struct object * try = weak_lock(&struct_weak_pointer);

    release_pointer_to_object(pointer_to_struct_object);

    return 0;

}
