#include <stdio.h>
#include "stack_overflow.h"

// Fonction récursive infinie pour provoquer un Stack Overflow
void stackOverflow(int depth) {
    int large_array[100000000];  // Allocation sur la pile
    large_array[0] = depth;  // Force l'utilisation de la mémoire pour éviter l'optimisation du compilateur
    printf("appel : %d\n", depth);
    stackOverflow(depth + 1);
}
