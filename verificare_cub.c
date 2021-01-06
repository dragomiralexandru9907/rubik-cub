#include "verificare_cub.h"
#include "stdio.h"
#include "pasul2.h"

/**@brief
 *
 * @param x culorile piesei actuale
 * @param y
 * @param culoare1 culorile cautate ale piesei
 * @param culoare2
 * @return 1 daca cubul este intodus corect, 0 altfel
 */
int verif( int x, int y, int culoare1, int culoare2)
{
    if((x == culoare2 && y == culoare1) || (x == culoare1 && y == culoare2))
        return 1;
    return 0;
}

int potrivire_culoare_colturi(int cub[10][10][10], int culoare0, int culoare1, int culoare2){
    int ok = 0 ;
    if(verificare(cub[1][0][2], cub[2][0][0], cub[5][2][2], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[1][0][0], cub[4][0][2], cub[5][2][0], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[1][2][0], cub[4][2][2], cub[0][0][0], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[1][2][2], cub[2][2][0], cub[0][0][2], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[3][2][0], cub[5][0][0], cub[4][0][0], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[3][2][2], cub[2][0][2], cub[5][0][2], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[3][0][0], cub[0][2][0], cub[4][2][0], culoare0, culoare1, culoare2))
        ok++;
    if(verificare(cub[3][0][2], cub[0][2][2], cub[2][2][2], culoare0, culoare1, culoare2))
        ok++;
    if(ok != 1)
        return 0;
    return 1;
}

int potrivire_culoare(int cub[10][10][10], int i, int j){
    int ok = 0 ;
    if(verif(cub[1][0][1], cub[5][2][1], i, j) )
        ok ++;
    if(verif(cub[1][1][0], cub[4][1][2], i, j) )
        ok ++;
    if(verif(cub[1][2][1], cub[0][0][1], i, j) )
        ok ++;
    if(verif(cub[1][1][2], cub[2][1][0], i, j) )
        ok ++;
    if(verif(cub[5][1][2], cub[2][0][1], i, j) )
        ok ++;
    if(verif(cub[5][1][0], cub[4][0][1], i, j) )
        ok ++;
    if(verif(cub[0][1][2], cub[2][2][1], i, j) )
        ok ++;
    if(verif(cub[0][1][0], cub[4][2][1], i, j) )
        ok ++;
    if(verif(cub[3][2][1], cub[5][0][1], i, j) )
        ok ++;
    if(verif(cub[3][1][0], cub[4][1][0], i, j) )
        ok ++;
    if(verif(cub[3][0][1], cub[0][2][1], i, j) )
        ok ++;
    if(verif(cub[3][1][2], cub[2][1][2], i, j) )
        ok ++;
    if(ok != 1)
        return 0;
    return 1;
}
int verificare_cub(int cub[10][10][10]){
    if(cub[4][1][1] != 4 || cub[3][1][1] != 3 || cub[2][1][1] != 2 ||cub[1][1][1] != 1 || cub[0][1][1] != 0 || cub[5][1][1] != 5)
        return 0;
    if(potrivire_culoare(cub, 1, 4) == 0)
        return 0;
    if(potrivire_culoare(cub, 1, 5) == 0)
        return 0;
    if(potrivire_culoare(cub, 1, 2) == 0)
        return 0;
    if(potrivire_culoare(cub, 1, 0) == 0)
        return 0;
    if(potrivire_culoare(cub, 5, 4) == 0)
        return 0;
    if(potrivire_culoare(cub, 5, 2) == 0)
        return 0;
    if(potrivire_culoare(cub, 0, 4) == 0)
        return 0;
    if(potrivire_culoare(cub, 0, 2) == 0)
        return 0;
    if(potrivire_culoare(cub, 3, 4) == 0)
        return 0;
    if(potrivire_culoare(cub, 3, 5) == 0)
        return 0;
    if(potrivire_culoare(cub, 3, 2) == 0)
        return 0;
    if(potrivire_culoare(cub, 3, 0) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 1, 2, 0) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 1, 2, 5) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 1, 4, 5) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 1, 4, 0) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 3, 5, 2) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 3, 5, 4) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 3, 4, 0) == 0)
        return 0;
    if (potrivire_culoare_colturi(cub, 3, 2, 0) == 0)
        return 0;
    return 1;
}