#include <stdio.h>
#include "citire-afisare.h"

/**@brief
 *
 * @param fata retine culoarea fetei citite
 * @param f fisierul de unde se preiau datele
 */
void citire_fata_cub(int fata[10][10], FILE *f){

    for( int i = 0 ; i < 3 ; i ++ )
        for( int j = 0 ; j < 3 ; j ++ )
         fscanf(f,"%d", &fata[i][j]);
}

void citire( int v[10][10][10] )
{
    FILE *f = fopen("fisier.txt", "r");
    for( int i = 0 ; i < 6 ; i ++ )
        citire_fata_cub(v[i],f);
    fclose(f);
}

void afisare( int cub[10][10][10] ) {
    FILE *f = fopen("afisare.txt", "w");
    for (int j = 0; j < 3; j++) {
        fprintf(f, "\t\t\t");
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[3][j][k]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
    for (int j = 0; j < 3; j++) {
        fprintf(f, "\t\t\t");
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[5][j][k]);
        fprintf(f, "\n");
    }

    fprintf(f, "\n");
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[4][j][k]);
        fprintf(f, "\t");
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[1][j][k]);
        fprintf(f, "\t");
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[2][j][k]);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
    for (int j = 0; j < 3; j++) {
        fprintf(f, "\t\t\t");
        for (int k = 0; k < 3; k++)
            fprintf(f, "%d  ", cub[0][j][k]);
        fprintf(f, "\n");
    }
/*
    for (int i = 0; i < 6; i++) {
        fprintf(f, "fata\n");
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                fprintf(f, "%d  ", cub[i][j][k]);
            fprintf(f, "\n");
        }
    }
    */
    fclose(f);
}