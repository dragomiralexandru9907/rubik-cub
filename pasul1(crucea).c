#include "pasul1(crucea).h"
#include "stdio.h"
#include "rotire-cub.h"
#include "citire-afisare.h"

void cruce_maker(int cub[10][10][10])
{
    int culoare1 = cub[1][1][1], culoare2 = cub[0][1][1];
    if(cub[1][2][1] == culoare2 && cub[0][0][1] == culoare1)
        front_face(cub);
    //verificare lateral jos
    if((cub[0][1][2] == culoare2 && cub[2][2][1] == culoare1)||(cub[0][1][2] == culoare1 && cub[2][2][1] == culoare2))
        right_face(cub);
    if((cub[0][1][0] == culoare1 && cub[4][2][1] == culoare2) || (cub[0][1][0] == culoare2 && cub[4][2][1] == culoare1))
        left_face(cub);
    //verificare spatele cubului
    if((cub[0][2][1] == culoare2 && cub[3][0][1] == culoare1) || (cub[0][2][1] == culoare1 && cub[3][0][1] == culoare2)){
        back_face(cub);
        back_face(cub);
    }
    if((cub[3][1][2] == culoare1 && cub[2][1][2] == culoare2) || (cub[3][1][2] == culoare2 && cub[2][1][2] == culoare1)){
        right_face_prim(cub);
        up_face(cub);
        right_face(cub);
    }
    if((cub[4][1][0] == culoare2 && cub[3][1][0] == culoare1) || (cub[4][1][0] == culoare1 && cub[3][1][0] == culoare2)){
        left_face_prim(cub);
        up_face_prim(cub);
        left_face(cub);
    }

    if((cub[5][0][1] == culoare1 && cub[3][2][1] == culoare2) || (cub[5][0][1] == culoare2 && cub[3][2][1] == culoare1)){
        up_face(cub);
        up_face(cub);
    }
    if((cub[5][1][2] == culoare2 && cub[2][0][1] == culoare1) || (cub[5][1][2] == culoare1 && cub[2][0][1] == culoare2))
        up_face(cub);
    if((cub[5][1][0] == culoare1 && cub[4][0][1] == culoare2) || (cub[5][1][0] == culoare2 && cub[4][0][1] == culoare1))
        up_face_prim(cub);

    if(cub[1][1][0] == culoare1 && cub [4][1][2] == culoare2)
        front_face(cub);
    if(cub[1][0][1] == culoare1 && cub [5][2][1] == culoare2){
        front_face(cub);
        front_face(cub);
    }
    if(cub[1][1][2] == culoare1 && cub [2][1][0] == culoare2){
        front_face_prim(cub);
    }
    //daca sunt pe dos culorile
    if(cub[1][1][0] == culoare2 && cub [4][1][2] == culoare1) {
        left_face(cub);
        up_face_prim(cub);
        left_face_prim(cub);
        front_face(cub);
        front_face(cub);
    }
    if(cub[1][0][1] == culoare2 && cub [5][2][1] == culoare1){
        up_face_prim(cub);
        right_face_prim(cub);
        front_face_prim(cub);
        right_face(cub);
    }
    if(cub[1][1][2] == culoare2 && cub [2][1][0] == culoare1){
        right_face(cub);
        up_face(cub);
        right_face_prim(cub);
        front_face(cub);
        front_face(cub);
    }
    //sf pe dos

}

void cruce(int cub[10][10][10] ) {
    cruce_maker(cub);//prima piesa
   // afisare(cub);
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    cruce_maker(cub);//a doua piesa
    //afisare(cub);
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    cruce_maker(cub);//a treia piesa
//    afisare(cub);
    up_face(cub);
    middle_face(cub);
    down_face(cub);
    cruce_maker(cub);//a patra piesa
    //readucerea cubului la pozitia initiala
    up_face(cub);
    middle_face(cub);
    down_face(cub);
}