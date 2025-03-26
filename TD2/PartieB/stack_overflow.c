#include <stdio.h>
#include "stack_overflow.h"

// Fonction récursive infinie pour provoquer un Stack Overflow
void stackOverflow() {
    int largeArray[10000];
    printf("Adresse de largeArray : %p\n", (void *)largeArray);
    stackOverflow();  
}
