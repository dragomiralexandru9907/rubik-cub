#include "pasul4.h"
#include "rotire-cub.h"
#include "stdio.h"
/**@brief
 *
 * @param cub cubul rubik
 */
void algorithm(int cub[10][10][10]){
    front_face_prim(cub);
    up_face(cub);
    right_face(cub);
    up_face_prim(cub);
    right_face_prim(cub);
    front_face(cub);
}

void top_x(int cub[10][10][10]){
    int ok = 0 ;
    //5 reprezinta culoarea galben
    if(cub[5][1][0] != 5 && cub[5][1][2] != 5 && cub[5][0][1] != 5 && cub[5][2][1] != 5)
        algorithm(cub);
    while( cub[5][1][0] != 5 || cub[5][1][2] != 5 || cub[5][0][1] != 5 || cub[5][2][1] != 5){
        ok ++;
        for(int i = 0 ; i < 4 ; i ++) {
            if (cub[5][0][1] == 5 && cub[5][1][0] == 5 && cub[5][1][2] != 5)
                algorithm(cub);
            up_face(cub);
        }
        if(cub[5][1][0] == 5 && cub[5][1][2] == 5 && cub[5][2][1] != 5)
            algorithm(cub);
        if(cub[5][1][0] == 5 && cub[5][1][2] == 5 && cub[5][2][1] != 5)
            algorithm(cub);
        up_face(cub);
        if(ok == 8)
            break;
    }
    if (ok == 8)
        printf("Eroare la pasul 4\n");
}