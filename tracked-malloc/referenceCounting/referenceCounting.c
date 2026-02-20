#include <stddef.h> /*size_t*/
#include <stdlib.h> /*malloc();*/
#include <stdio.h>


typedef void (* deallocator)(void *);

struct refcount {
	int count;
	deallocator free;
};


/*size_t is an unsigned integer*/
static void * rc_malloc(size_t size, deallocator free) { /*void * require return value or it will raise a warning*/

	/*
	The addition of + size in the malloc call is necessary
	because the memory allocation needs to include space for both the metadata (struct refcount)
	and the actual user data requested by the caller.
	*/
	struct refcount * p = malloc(sizeof(struct refcount) + size);

	/*suppresse warning about possibility dereferencing nullptr*/
	if (p) * p = (struct refcount){.count = 1, .free = free};

	/*
	p + 1 increments p by 1 unit of the size of struct refcount,
	effectively moving the pointer past the metadata portion of the memory.
	
	1. Separate Metadata from User Data:
	   a. The allocated memory block includes both :
		  1. Metadata (struct refcount): Used internally by the memory management system.
		  2. User data: The memory requested by the caller.
	   b. By returning (p + 1), the user only sees the memory intended for their use,
	   	  and they remain unaware of the metadata.
	
	2. Encapsulation:
	   a. This design encapsulates the reference-counting mechanism,
	   	  preventing the caller from accidentally modifying the metadata.
	   b. The caller interacts only with the memory they requested,
	   	  without worrying about how the reference count is managed
	*/
	return p + 1;

}


static void print_free(void * p) {

	int * ip = p;

	printf("freeing %d\n", * ip);

}


static void * incref(void * p) {

	if (!p) return p;

}


int main() {

	/*
	sizeof(data type)
	sizeof expression
	*/

	int * p = rc_malloc(sizeof * p, print_free);

	/*
	Assigning 42 ensures there is a visible,
	meaningful value stored in the memory that can be observed when it is eventually freed.
	Ensures that the allocated memory contains a meaningful value (42) that can be printed during deallocation,
	making the behavior of the program more observable and meaningful in this example.
	*/
	* p = 42;

	int * p2 = incref(p);

}
