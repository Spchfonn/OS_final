#include <stdio.h>
#include <stdlib.h>

// Global variables
int global_var1 = 1;
int global_var2 = 2;
int global_var3 = 3;

// Function to display addresses in the call stack
void stackFunction3() {
    int local_var3 = 30;
    printf("Address of local_var3 in stackFunction3: %p\n", (void*)&local_var3);
}

void stackFunction2() {
    int local_var2 = 20;
    printf("Address of local_var2 in stackFunction2: %p\n", (void*)&local_var2);
    stackFunction3();
}

void stackFunction1() {
    int local_var1 = 10;
    printf("Address of local_var1 in stackFunction1: %p\n", (void*)&local_var1);
    stackFunction2();
}

int main() {
    // Display addresses of global variables
    printf("Address of global_var1: %p\n", (void*)&global_var1);
    printf("Address of global_var2: %p\n", (void*)&global_var2);
    printf("Address of global_var3: %p\n", (void*)&global_var3);

    // Display addresses of heap memory allocations
    int *heap_var1 = (int*)malloc(sizeof(int));
    int *heap_var2 = (int*)malloc(sizeof(int));
    int *heap_var3 = (int*)malloc(sizeof(int));
    printf("Address of heap_var1: %p\n", (void*)heap_var1);
    printf("Address of heap_var2: %p\n", (void*)heap_var2);
    printf("Address of heap_var3: %p\n", (void*)heap_var3);

    // Call stack functions
    stackFunction1();

    // Free allocated memory
    free(heap_var1);
    free(heap_var2);
    free(heap_var3);

    return 0;
}
