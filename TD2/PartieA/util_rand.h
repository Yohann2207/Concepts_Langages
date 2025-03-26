#ifndef UTIL_RAND_H
#define UTIL_RAND_H

#include <stdlib.h>
#include <time.h>

void init_random();

int rand_max();

int rand_seuil_haut(int max);

int rand_borne(int min, int max);

double rand_0_1();

double rand_borne_decimale(double min, double max);

#endif
