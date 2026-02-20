#include "stdio.h"
#include "stdlib.h" /*malloc();*/

/* deallocator, is a pointer to function that take void pointer as a parameter, returning void */
typedef void(* deallocator)(void *);

struct refcount {int count; deallocator free;};


void * rc_malloc(size_t size, deallocator free) {

	/*
	the addition of + size in the malloc call is necessary
	because the memory allocation needs to include space both metadata (refcount)
	and the actual user data requested by the caller
	*/
	struct refcount * p = (struct refcount *)malloc(sizeof(struct refcount) + size);

	/*suppressed warning about possibility derefenrencing nullptr*/
	if (p) * p = (struct refcount){.count = 1, .free = free};

	/*
	p + 1 increments p by 1 unit of the size of struct refcount,
	effectively moving the pointer past the metadata portion of the memory.
	
	1. separation metadata from user data
		a. The allocated memory block includes both :
			1. metadata (struct refcount) : used internally by the memory management system
			2. user data : the memory requested by the caller.
		b. by returning (p + 1) the user only sees the memory intended for their use,
			and they remain unaware of the metadata
	
	2. encapsulation
		a. this design encapsulates the reference-counting mechanism,
			preventing the caller from accidentally modifying the metadata
		b. the caller interacts only with the memory they requested,
			without worrying about how the reference count is managed
	*/
	return p + 1;

	/*suppressed warning: control reaches end of non-void function [-Wreturn-type] }*/
	return 0;

}


void print_free(void * p) {

	int * ip = p;

	printf("freeing %d\n", * ip);

}


void * incref(void * p) {

	/*
	1. check if p is NULL
		if (!p) is a shorthand for if (NULL == p), meaning "if p is NULL, then ..."
	
	2. return NULL if p is NULL
		return p; effectively returns NULL, ensuring that if a NULL pointer is passed to incref();,
		it will return NULL without attempting any further operations
	*/
	if (!p) return p;

	struct refcount * rc = (struct refcount *)p - 1;

	rc->count++;

	return rc + 1;

}


int main() {

	/*
	sizeof(datatype);
	sizeof expression;
 	printf("%ld", sizeof 1);
	*/

	int * p = rc_malloc(sizeof * p, print_free);

	/*
	assigning 42 ensures there is a visible, meaningful value stored in the memory
	that can be observe when it is eventually freed

	ensures that the allocated memory contain a meaningful value (42) that can be printed during deallocation,
	making the behavior of the program more observable and meaningful in this example
	*/
	* p = 42;

	int * p2 = incref(p);










}





