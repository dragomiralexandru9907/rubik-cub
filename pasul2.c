#include "pasul2.h"
#include "stdio.h"
#include "rotire-cub.h"
#include "citire-afisare.h"

int verificare(int x, int y, int z, int culoare0, int culoare1, int culoare2)
{//verifca daca piesa este cea cautata
    if(x == culoare0 && y == culoare1 && z == culoare2)
        return 1;
    if(x == culoare0 && y == culoare2 && z == culoare1)
        return 1;
    if(x == culoare1 && y == culoare2 && z == culoare0)
        return 1;
    if(x == culoare1 && y == culoare0 && z == culoare2)
        return 1;
    if(x == culoare2 && y == culoare0 && z == culoare1)
        return 1;
    if(x == culoare2 && y == culoare1 && z == culoare0)
        return 1;
    return 0;
}

void colt(int cub[10][10][10]){
    //fixeaza colturile
    if(verificare(cub[2][2][2], cub[3][0][2], cub[0][2][2], 0, cub[2][1][1], cub[1][1][1])) {
        back_face(cub);
        up_face(cub);
        back_face_prim(cub);
    }
    if(verificare(cub[4][2][0], cub[3][0][0], cub[0][2][0], 0, cub[2][1][1], cub[1][1][1])){
        left_face_prim(cub);
        up_face(cub);
        left_face(cub);
    }
    if(verificare(cub[1][2][0], cub[0][0][0], cub[4][2][2], 0, cub[2][1][1], cub[1][1][1])){
        left_face(cub);
        up_face_prim(cub);
        left_face_prim(cub);
    }
    int nr = 0;
    while(verificare(cub[1][2][2], cub[0][0][2], cub[2][2][0], 0, cub[1][1][1], cub[2][1][1]) == 0){
        right_face(cub);
        up_face_prim(cub);
        right_face_prim(cub);
        nr++;
        if(nr == 6)
            break;
    }
    if(nr == 6)
        printf("Eroare la pasul 2");
    nr = 0 ;
    while(cub[0][0][2] != 0)
    {
        right_face(cub);
        up_face(cub);
        right_face_prim(cub);
        up_face_prim(cub);
        right_face(cub);
        up_face(cub);
        right_face_prim(cub);
        nr++;
        if(nr == 6)
            break;
    }
    if(nr == 6)
        printf("Eroare la pasul 2");
}

void completare_alb(int cub[10][10][10]){
    colt(cub);//primul colt
    //afisare(cub);
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    colt(cub);//al doilea colt
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    colt(cub);//al treilea colt
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    colt(cub);//al patrulea colt
    //readucerea la pozitia initiala
    up_face(cub);
    middle_face(cub);
    down_face(cub);
}