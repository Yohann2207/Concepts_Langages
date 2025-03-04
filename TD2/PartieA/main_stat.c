#include <stdio.h>
#include "stat_rand.h"

int main() {
    init_random();
    test_stat_rand(100000);
    return 0;
}
