#include <stdio.h>
#include <stdlib.h>

/* forward */
typedef struct Control Control;

typedef struct Object {
    Control *ctrl;
    int value;
} Object;

struct Control {
    int strong;
    int weak;
    Object *obj;
};

/* create object */
Object *object_create(int value) {
    Control *c = malloc(sizeof *c);
    Object  *o = malloc(sizeof *o);

    c->strong = 1;
    c->weak   = 0;
    c->obj    = o;

    o->ctrl = c;
    o->value = value;

    printf("create object %p\n", (void*)o);
    return o;
}

/* strong retain */
void object_retain(Object *o) {
    if (!o) return;
    o->ctrl->strong++;
}

/* strong release */
void object_release(Object *o) {
    if (!o) return;

    Control *c = o->ctrl;
    if (--c->strong == 0) {
        printf("destroy object %p\n", (void*)o);
        free(o);
        c->obj = NULL;

        if (c->weak == 0) {
            free(c);
        }
    }
}

/* weak pointer type */
typedef struct {
    Control *ctrl;
} Weak;

/* create weak */
Weak weak_create(Object *o) {
    Weak w = {0};
    if (!o) return w;

    w.ctrl = o->ctrl;
    w.ctrl->weak++;
    return w;
}

/* lock weak → strong */
Object *weak_lock(Weak *w) {
    if (!w->ctrl) return NULL;

    if (w->ctrl->strong == 0)
        return NULL; /* object already destroyed */

    w->ctrl->strong++;
    return w->ctrl->obj;
}

/* destroy weak */
void weak_release(Weak *w) {
    if (!w->ctrl) return;

    Control *c = w->ctrl;
    if (--c->weak == 0 && c->strong == 0) {
        free(c);
    }
    w->ctrl = NULL;
}


int main(void) {
    Object *a = object_create(123);

    Weak w = weak_create(a);

    object_release(a);   /* destroys object */

    Object *try = weak_lock(&w);
    if (!try)
        printf("weak expired\n");
    else
        object_release(try);

    weak_release(&w);
    return 0;
}
