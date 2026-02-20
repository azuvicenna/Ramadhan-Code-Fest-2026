/*
Reference Counting Lists In C


i was playing with reference counting garbage collection last week, for something i want to add to my C pointers book.
That chapter is still far in the future, and moving further into the book as the book seems to grow in front of me,
but one day I will get to it. And by then, i have to figure out some design issues that I ran into.


Reference Counting Garbage Collection

the idea is simple enough. Instead of having some designated "owner" of an object,
responsible for freeing it when we no longer need it, we keep a count of how many reference we have to the object.
We increment the reference count when we make another reference, and we decrement it again when we remove a reference.
No problem there.

i have seen implememtations like the one below several places, and it gives an idea about what we are aiming at
(but it has some issues that i will describe bellow).
*/

#include <stdlib.h>
#include <stdio.h>

typedef void (* deallocator)(void *);

struct refcount{int count; deallocator free;};


void * rc_malloc(size_t size, deallocator free) {

	struct refcount * p = malloc(sizeof(struct refcount) + size);

	* p = (struct refcount){.count = 1, .free = free};

	return p + 1;

}


void print_free(void * p) {

	int * ip = p;

	printf("freeing %d\n", * ip);

}


int main() {

	/*
	sizeof(datatype);
	sizeof expression;
	printf("%ld", sizeof 1);
	*/
	int * p = rc_malloc(sizeof * p, print_free);


}


/*
An object that we manage with reference counting has count and a function we should call when it should be freed.
typedef void(* deallocator)(void *)
struct refcount {int count; deallocator free};

I used int for count, although it is never supposed to be negative.\
A signed integer make it easier to discover if I managed to get underflow
-but an assert() might be in order to prevent it from happening.
But there is also another reason. It can be faster to work with signed than unsigned integers in C.
The standard requires that unsigned integers work with modular arithmetic,
but signed integers can work as whatever the hardware says it should work like.
The compiler thus might haveto emit extra code if we insist on working with unsigned integers.
Here, I dont expect to reference more than I can count in the positive part of an integer
(and if I did, I could go for  a larger integer type),
so I might as well get faster code and code that is easier to debug.

There might more functions you need beyond free();,
and in that case the function pointer should be a pointer to a struct functions,
but for our purposes this suffices.
The free(); function should decrement other counts, if the object hold references, but I get to that later.

The main problem with this code has nothing to do with reference counting,
I just want to bring it up here,
because I have seen such code at least a handful of times while googling around for reference counting example.
When we allocate memory, we allocate a number of bytes
(well, sizeof(char)); similar to how we use malloc();,
but the rc_malloc(); function first allocates space for the reference counting structure.
It initialises that, and return the address after the struct.
When the p pointer has type struct refcount *, the address p + 1 is the one right after the structure.
The rc_free()





*/













