#include <stdio.h>
#include "citire-afisare.h"
#include "rotire-cub.h"
#include "pasul1(crucea).h"
int main() {
int cub[10][10][10];

citire(cub);
//front_face(cub);
//right_face(cub);
//right_face(cub);
//left_face(cub);
//up_face(cub);
//down_face(cub);
//middle_face(cub);
//down_face(cub);
cruce(cub);
afisare(cub);
}
