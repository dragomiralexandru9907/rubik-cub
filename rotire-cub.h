#define pragmaonce
/*
 * 0 - jos
 * 1 - fat
 * 2 - dreapta
 * 3 - spate
 * 4 - stanga
 * 5 - sus
 */
void right_face(int cub[10][10][10]);//R
void left_face(int cub[10][10][10]);//pe invers fata de cum e in regulament(L <- LI)
void rotire_fata( int cub[10][10][10], int fata);
void back_face(int cub[10][10][10]);//B
void front_face(int cub[10][10][10]);//pe invers fata de cum e in regulament(F <- FI)
void up_face(int cub[10][10][10]);//U
void down_face(int cub[10][10][10]);//pe invers fata de cum e in regulament(D <- DI)
void middle_face(int cub[10][10][10]);//pas suplimentar pentru a se putea efectua rotirea totala a cubului
void right_face_prim(int cub[10][10][10]);
void down_face_prim(int cub[10][10][10]);
void up_face_prim(int cub[10][10][10]);
void front_face_prim(int cub[10][10][10]);
void back_face_prim(int cub[10][10][10]);
void left_face_prim(int cub[10][10][10]);

