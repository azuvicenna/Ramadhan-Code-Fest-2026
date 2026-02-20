#include "stdio.h" 


void hello(char * name, int age) {

    printf("%s %d\n", name, age);

}


int main() {

    char * string;

    size_t age = 20;

    string = "immutable stack";

    hello(string = "Nengkya Gagah", age = 21);

    return 0;

}
