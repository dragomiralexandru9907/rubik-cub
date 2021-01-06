#include "pasul5.h"
#include "rotire-cub.h"
#include "stdio.h"
#include "citire-afisare.h"
#include "stdio.h"

void algorithm_pasul5(int cub[10][10][10]){
    right_face(cub);
    up_face(cub);
    right_face_prim(cub);
    up_face(cub);
    right_face(cub);
    up_face(cub);
    up_face(cub);
    right_face_prim(cub);
}

void creare_fata_galbena(int cub[10][10][10]){
    int ok = 0;
    //5 reprezinta culoarea galben
    while (cub[5][0][0] != 5 || cub[5][0][2] != 5 || cub[5][2][2] != 5){
        ok ++;
        for(int i = 0 ; i < 4 ; i ++ )//caz 1
        {
            if(cub[5][2][0] == 5 && cub[5][0][0] != 5 && cub[5][0][2] != 5 && cub[5][2][2] != 5)
                algorithm_pasul5(cub);
            up_face(cub);
        }
        for(int i = 0 ; i < 4 ; i ++ )//caz 2
        {
            if(cub[4][0][2] == 5 && cub[5][2][0] != 5 && cub[5][0][0] != 5 && cub[5][0][2] != 5 && cub[5][2][2] != 5)
                algorithm_pasul5(cub);
            up_face(cub);
        }
        for(int i = 0 ; i < 4 ; i ++ )//caz 3
        {
            if(cub[1][0][0] == 5 && cub[5][0][0] == 5 && cub[5][0][2] == 5 && cub[5][2][2] != 5)
                algorithm_pasul5(cub);
            up_face(cub);
        }
        for(int i = 0 ; i < 4 ; i ++ )//caz 4
        {
            if(cub[1][0][0] == 5 && cub[5][0][0] == 5 && cub[5][0][2] != 5 && cub[5][2][2] == 5)
                algorithm_pasul5(cub);
            up_face(cub);
        }
        for(int i = 0 ; i < 4 ; i ++ )//caz 5
        {
            if(cub[1][0][0] == 5 && cub[5][0][0] != 5 && cub[5][0][2] == 5 && cub[5][2][2] == 5)
                algorithm_pasul5(cub);
            up_face(cub);
        }
        if(ok == 6)
            break;
    }
    if(ok == 6)
        printf("Eroare la pasul 5\n");
    //afisare(cub);
}