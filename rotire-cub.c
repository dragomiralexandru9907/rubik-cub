#include "rotire-cub.h"
#include "stdio.h"

/**@brief
 *
 * @param cub cubul rubik
 * @param fata culoarea fetei cubului rubik pe care vrem sa efectuam rotirea
 */
void rotire_fata( int cub[10][10][10], int fata)
{
    int aux1, aux2 ;
    aux1 = cub[fata][0][1];
    aux2 = cub[fata][0][2];
    cub[fata][0][2] = cub[fata][0][0];
    cub[fata][0][1] = cub[fata][1][0];
    cub[fata][0][0] = cub[fata][2][0];

    cub[fata][2][0] = cub[fata][2][2];
    cub[fata][1][0] = cub[fata][2][1];

    cub[fata][2][1] = cub[fata][1][2];
    cub[fata][2][2] = aux2;

    cub[fata][1][2] = aux1;
}

void right_face(int cub[10][10][10]){

    int aux0 = cub[3][0][2], aux1 = cub[3][1][2], aux2 = cub[3][2][2];
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cub[3][i][2] = cub[5][i][2];
        cub[5][i][2] = cub[1][i][2];
        cub[1][i][2] = cub[0][i][2];
    }
    cub[0][0][2] = aux0;
    cub[0][1][2] = aux1;
    cub[0][2][2] = aux2;

    rotire_fata(cub, 2);
}

void left_face(int cub[10][10][10]){

    int aux0 = cub[3][0][0], aux1 = cub[3][1][0], aux2 = cub[3][2][0];
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cub[3][i][0] = cub[5][i][0];
        cub[5][i][0] = cub[1][i][0];
        cub[1][i][0] = cub[0][i][0];
    }
    cub[0][0][0] = aux0;
    cub[0][1][0] = aux1;
    cub[0][2][0] = aux2;

    rotire_fata(cub, 4);
    rotire_fata(cub, 4);
    rotire_fata(cub, 4);
}

void back_face(int cub[10][10][10])
{
    int aux0 = cub[5][0][0], aux1 = cub[5][0][1], aux2 = cub[5][0][2];
    for( int i = 0 ; i < 3 ; i ++ ){
        cub[5][0][i] = cub[2][i][2];
    }
    for( int i = 0 ; i < 3 ; i ++ ){
         cub[2][2-i][2] = cub[0][2][i];
    }
    for( int i = 0 ; i < 3 ; i ++ ) {
        cub[0][2][i] = cub[4][i][0];
    }
    cub[4][0][0] = aux2 ;
    cub[4][1][0] = aux1 ;
    cub[4][2][0] = aux0 ;

    rotire_fata(cub, 3);
}

void front_face(int cub[10][10][10])
{
    int aux0 = cub[5][2][0], aux1 = cub[5][2][1], aux2 = cub[5][2][2];
    for( int i = 0 ; i < 3 ; i ++ ){
        cub[5][2][i] = cub[2][i][0];
    }
    for( int i = 0 ; i < 3 ; i ++ ){
        cub[2][2-i][0] = cub[0][0][i];
    }
    for( int i = 0 ; i < 3 ; i ++ ) {
        cub[0][0][i] = cub[4][i][2];
    }
    cub[4][0][2] = aux2 ;
    cub[4][1][2] = aux1 ;
    cub[4][2][2] = aux0 ;

    rotire_fata(cub, 1);
    rotire_fata(cub, 1);
    rotire_fata(cub, 1);
}

void up_face(int cub[10][10][10])
{
    int aux0 = cub[3][2][0], aux1 = cub[3][2][1], aux2 = cub[3][2][2];
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cub[3][2][i] = cub[4][0][2-i];
    }
    for( int i = 0 ; i < 3 ; i ++ )
    {
         cub[4][0][i] = cub[1][0][i];
         cub[1][0][i]= cub[2][0][i];
    }
    cub[2][0][0] = aux2 ;
    cub[2][0][1] = aux1 ;
    cub[2][0][2] = aux0 ;

    rotire_fata(cub, 5);
}

void down_face(int cub[10][10][10])
{
    int aux0 = cub[3][0][0], aux1 = cub[3][0][1], aux2 = cub[3][0][2];
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cub[3][0][i] = cub[4][2][2-i];
    }
    for( int i = 0 ; i < 3 ; i ++ )
    {
        cub[4][2][i] = cub[1][2][i];
        cub[1][2][i] = cub[2][2][i];
    }
    cub[2][2][0] = aux2 ;
    cub[2][2][1] = aux1 ;
    cub[2][2][2] = aux0 ;

    rotire_fata(cub, 0);
    rotire_fata(cub, 0);
    rotire_fata(cub, 0);
}

void middle_face(int cub[10][10][10]) {
    int aux0 = cub[3][1][0], aux1 = cub[3][1][1], aux2 = cub[3][1][2];
    for (int i = 0; i < 3; i++) {
        cub[3][1][i] = cub[4][1][2 - i];
    }
    for (int i = 0; i < 3; i++) {
        cub[4][1][i] = cub[1][1][i];
        cub[1][1][i] = cub[2][1][i];
    }
    cub[2][1][0] = aux2;
    cub[2][1][1] = aux1;
    cub[2][1][2] = aux0;
}

void right_face_prim(int cub[10][10][10]){
    right_face( cub);
    right_face( cub);
    right_face( cub);
}
void down_face_prim(int cub[10][10][10]){
    down_face( cub);
    down_face( cub);
    down_face( cub);
}
void up_face_prim(int cub[10][10][10]){
    up_face( cub);
    up_face( cub);
    up_face( cub);
}
void front_face_prim(int cub[10][10][10]){
    front_face( cub);
    front_face( cub);
    front_face( cub);
}
void back_face_prim(int cub[10][10][10]){
    back_face( cub);
    back_face( cub);
    back_face( cub);
}
void left_face_prim(int cub[10][10][10]){
    left_face( cub);
    left_face( cub);
    left_face( cub);
}
