#include <stdio.h>
#include "citire-afisare.h"
#include "rotire-cub.h"
#include "pasul1(crucea).h"
#include "pasul2.h"
#include "verificare_cub.h"
#include "pasul3.h"
#include "pasul4.h"
#include "pasul5.h"
#include "pasul6.h"
#include "pasul7.h"

int main() {

int cub[10][10][10];
citire(cub);
if(verificare_cub(cub) == 0)
    printf("Cubul introdus nu este corect");
cruce(cub);//pasul1
completare_alb(cub);//pasul2
layer2(cub);//pasul3
top_x(cub);//pas4
creare_fata_galbena(cub);//pasul 5
pozitionare_colturi(cub);//pasul 6
aranjare_muchii(cub);//pasul 7
afisare(cub);
}
