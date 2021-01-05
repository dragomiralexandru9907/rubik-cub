#include "pasul4.h"
#include "rotire-cub.h"

void algorithm(int cub[10][10][10]){
    front_face_prim(cub);
    up_face(cub);
    right_face(cub);
    up_face_prim(cub);
    right_face_prim(cub);
    front_face(cub);
}

void top_x(int cub[10][10][10]){
    
}