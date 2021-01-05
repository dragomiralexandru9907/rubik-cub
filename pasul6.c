#include "pasul6.h"
#include "rotire-cub.h"
#include "stdio.h"

void algorithm_pasul6(int cub[10][10][10]){
    right_face_prim(cub);
    front_face_prim(cub);
    right_face_prim(cub);
    back_face(cub);
    back_face(cub);
    right_face(cub);
    front_face(cub);
    right_face_prim(cub);
    back_face(cub);
    back_face(cub);
    right_face(cub);
    right_face(cub);
    up_face_prim(cub);
}

int verificare_pozitie_colturi(int cub[10][10][10]){
    if(cub[1][0][0] != cub[1][1][1] || cub[4][0][2] != cub[4][1][1])
        return 0;
    if(cub[1][0][2] != cub[1][1][1] || cub[2][0][0] != cub[2][1][1])
        return 0;
    if(cub[3][2][0] != cub[3][1][1] || cub[4][0][0] != cub[4][1][1])
        return 0;
    if(cub[2][0][2] != cub[2][1][1] || cub[3][2][2] != cub[3][1][1])
        return 0;
    return 1;
}

void pozitionare_colturi(int cub[10][10][10])
{
    int ok = 0, nr = 0;
    while(ok < 2){
        ok = 0;
        up_face(cub);
        if(cub[1][0][0] == cub[1][1][1] && cub[4][0][2] == cub[4][1][1])
            ok ++;
        if(cub[1][0][2] == cub[1][1][1] && cub[2][0][0] == cub[2][1][1])
            ok ++;
        if(cub[3][2][0] == cub[3][1][1] && cub[4][0][0] == cub[4][1][1])
            ok ++;
        if(cub[2][0][2] == cub[2][1][1] && cub[3][2][2] == cub[3][1][1])
            ok ++;
        nr++;
        if(nr == 6)
            break;
    }
    if(nr == 6)
        printf("Eroare la pasul 6");
    nr = 0;
    while (verificare_pozitie_colturi(cub) == 0){
        for (int i = 0; i < 4; i++) {
            if(cub[1][0][0] != cub[1][1][1] && cub[1][0][2] != cub[1][1][1])
                algorithm_pasul6(cub);
            up_face(cub);
            middle_face(cub);
            down_face(cub);
        }
        if(cub[1][0][0] == cub[1][1][1] && cub[1][0][2] != cub[1][1][1])
            algorithm_pasul6(cub);
        else{
            up_face(cub);
            middle_face(cub);
            down_face(cub);
            if(cub[1][0][0] == cub[1][1][1] && cub[1][0][2] != cub[1][1][1])
                algorithm_pasul6(cub);
            up_face_prim(cub);
            middle_face(cub);
            middle_face(cub);
            middle_face(cub);
            down_face_prim(cub);
        }
        nr ++;
        if(nr == 6)
            break;
    }
    if (nr == 6)
        printf("Eroare la pasul 6");
}