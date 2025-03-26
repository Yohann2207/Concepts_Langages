#include <stdio.h>

int main() {
    float Nlv, Nf, Nm, Np;
    
    Nlv = 12;
    Nf = 14;
    Nm = 9;
    Np = 8;

    float MoyenneG = (Nlv + Nf + Nm + Np) / 4;

    int expression_b1 = MoyenneG > 10;

    int expression_b2 = (Nm > MoyenneG) && (Nf > MoyenneG);

    int expression_b3 = (Nlv > 10) || (Nf > 10) || (Nm > 10) || (Np > 10);

    int expression_b4 = (Nlv > 10) && (Nf > 10) && (Nm > 10) && (Np > 10);

    float MoyenneL = (Nlv + Nf) / 2;
    float MoyenneS = (Nm + Np) / 2;

    int expression_b5 = (MoyenneL >= 10) || (MoyenneS >= 10);

    int expression_b6 = (MoyenneG >= 10) && ((MoyenneL == 10) ^ (MoyenneS == 10));

    printf("Condition 1: %d\n", expression_b1);
    printf("Condition 2: %d\n", expression_b2);
    printf("Condition 3: %d\n", expression_b3);
    printf("Condition 4: %d\n", expression_b4);
    printf("Condition 5: %d\n", expression_b5);
    printf("Condition 6: %d\n", expression_b6);
}