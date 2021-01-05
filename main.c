#include <stdio.h>
#include "citire-afisare.h"
#include "rotire-cub.h"
#include "pasul1(crucea).h"
#include "pasul2.h"
#include "verificare_cub.h"
#include "pasul3.h"
int main() {

int cub[10][10][10];
citire(cub);
if(verificare_cub(cub) == 0)
    printf("Cubul introdus nu este corect");
cruce(cub);//pasul1
completare_alb(cub);//pasul2
layer2(cub);//pasul3
afisare(cub);
}
