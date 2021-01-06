#include "pasul3.h"
#include "rotire-cub.h"
#include "verificare_cub.h"
#include "stdio.h"
#include "citire-afisare.h"
/**@brief
 *
 * @param cub cubul rubik
 */
void pozitionare_piesa_dreapta(int cub[10][10][10]){
    up_face(cub);
    right_face(cub);
    up_face_prim(cub);
    right_face_prim(cub);
    up_face_prim(cub);
    front_face(cub);
    up_face(cub);
    front_face_prim(cub);
}
void pozitionare_piesa_stanga(int cub[10][10][10]){
    up_face_prim(cub);
    left_face(cub);
    up_face(cub);
    left_face_prim(cub);
    up_face(cub);
    front_face_prim(cub);
    up_face_prim(cub);
    front_face(cub);
}
void layer2_peace_by_peace(int cub[10][10][10]){
    if(cub[1][1][2] == cub[2][1][1] && cub[2][1][0] == cub[1][1][1])
        pozitionare_piesa_dreapta(cub);
    if(verif(cub[1][1][1], cub[2][1][1], cub[2][1][2], cub[3][1][2]))
    {
        up_face(cub);
        down_face(cub);
        middle_face(cub);
        pozitionare_piesa_dreapta(cub);//scot piesa pe care o caut
        //repozitionare cub
        up_face_prim(cub);
        down_face_prim(cub);
        middle_face(cub);
        middle_face(cub);
        middle_face(cub);
    }
    if(verif(cub[1][1][1], cub[2][1][1], cub[4][1][0], cub[3][1][0]))
    {
        up_face(cub);
        down_face(cub);
        middle_face(cub);
        up_face(cub);
        down_face(cub);
        middle_face(cub);
        pozitionare_piesa_dreapta(cub);
        up_face(cub);
        down_face(cub);
        middle_face(cub);
        up_face(cub);
        down_face(cub);
        middle_face(cub);
    }
    if(verif(cub[1][1][1], cub[2][1][1], cub[1][1][0], cub[4][1][2]))
    {
        up_face_prim(cub);
        down_face_prim(cub);
        middle_face(cub);
        middle_face(cub);
        middle_face(cub);
        pozitionare_piesa_dreapta(cub);
        up_face(cub);
        down_face(cub);
        middle_face(cub);
    }
    for(int i = 0 ; i < 4 ; i ++ )
    {
        for(int j = 0 ; j < 4 ; j ++){
            if(cub[1][0][1] == cub[1][1][1] && cub[5][2][1] == cub[2][1][1])
                  pozitionare_piesa_dreapta(cub);
            up_face(cub);
        }
        middle_face(cub);
        down_face(cub);
    }
    for(int i = 0 ; i < 4 ; i ++ )
    {
        for(int j = 0 ; j < 4 ; j ++) {
            if (cub[1][0][1] == cub[1][1][1] && cub[5][2][1] == cub[4][1][1])
                pozitionare_piesa_stanga(cub);
            up_face(cub);
        }
        middle_face(cub);
        down_face(cub);
    }
}

void layer2(int cub[10][10][10]){
    layer2_peace_by_peace(cub);//piesa 1
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    layer2_peace_by_peace(cub);//piesa 2
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    layer2_peace_by_peace(cub);//piesa 3
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    layer2_peace_by_peace(cub);//piesa 4
    //repozitionarea cubului
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    //afisare(cub);
}