#include "pasul7.h"
#include "rotire-cub.h"
#include "stdio.h"
#include "citire-afisare.h"
#include "stdio.h"

void algorithm_pasul7(int cub[10][10][10]){
    front_face_prim(cub);
    front_face_prim(cub);
    up_face(cub);
    left_face_prim(cub);
    right_face_prim(cub);
    front_face_prim(cub);
    front_face_prim(cub);
    left_face(cub);
    right_face(cub);
    up_face(cub);
    front_face_prim(cub);
    front_face_prim(cub);
}

void aranjare_muchii(int cub[10][10][10]){
    int ok = 0, nr = 0 ;
    if(cub[3][2][1] != cub[3][1][1] && cub[2][0][1] != cub[2][1][1] && cub[1][0][1] != cub[1][1][1] && cub[4][0][1] != cub[4][1][1])
        algorithm_pasul7(cub);
    while (cub[3][2][1] != cub[3][1][1])
    {
        nr++;//pentru a aduce cubul la pozitia initiala
        up_face(cub);
        middle_face(cub);
        down_face(cub);
        if(nr == 4)
            break;
    }
    if(nr == 4)
        printf("Eroare la pasul 7\n");
    while ( cub[1][0][1] != cub[1][1][1] || cub[2][0][1] != cub[2][1][1])
    {
        algorithm_pasul7(cub);
        ok ++;
        if( ok == 6)
            break;
    }
    if(ok == 6)
        printf("Eroare la pasul 7\n");
    for( int i = 0 ; i < 4 - nr ; i ++ )
    {//pentru a readuce cubul la pozitia initiala
        up_face(cub);
        middle_face(cub);
        down_face(cub);
    }
    //afisare(cub);
}