#include <stdio.h>
#include <stdlib.h>

int sum(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Wrong usage, at least 2 parameters expected:\n");
        printf("./sum param1 param2\n");
        return 1;
    }

    int total = 0;
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num == 0 && argv[i][0] != '0') { // Vérification si la conversion est réussie
            printf("There is a problem with args %d, %s. It could not be transformed in int. Please retry !\n", i, argv[i]);
            return 1;
        }
        total += num;
    }
    return total;
}

int main(int argc, char *argv[]) {
    int result = sum(argc, argv);
    if (result != 1) {
        printf("%d\n", result);
    }
    return 0;
}
