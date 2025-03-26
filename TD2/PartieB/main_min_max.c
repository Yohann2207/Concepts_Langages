#include <stdio.h>
#include "min_max.h"

int main(){
    int *max;
    int taille = 6;
    int tab[] = {2,1,5,3,7,4};
    min_max(tab, taille, &max);
    printf("%d", *max);
}