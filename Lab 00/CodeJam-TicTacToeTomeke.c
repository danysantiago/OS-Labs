#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *archivo, *salida;
    archivo = fopen("entrada.txt","r");
    salida = fopen("salida.txt","w");

	int cases = 0;
    char dummy;
    char dumline[2];

    fscanf(archivo, "%d%c", &cases, &dummy);

    int i = 0;
    for (i; i < cases; i++) {

        char board[4][6];

        int line = 0;
        for (line; line < 4; line++) {
                fgets(board[line], 6, archivo);
                //fprintf(salida, "%s", board[line]); 
        }

        int row;
        int col;

        int empty = 0;
        int winPlayer = 0;
        int done = 0;

        for (row = 0; row < 4; row++) {

            // if (done == 1) {
            //     break;
            // }

            for (col = 0; col < 4; col++) {

                //printf("Inspecting %d,%d\n", row, col);

                //Check Right
                if(col == 0) {
                    int X = 0;
                    int O = 0;
                    int T = 0;

                    int m = 0;
                    for (m; m < 4; m++) {
                        char c = board[row][m];
                        if (c == 'X') {
                            X++;
                        } else if (c == 'O') {
                            O++;
                        } else if (c == '.') {
                            empty++;
                        } else if (c == 'T') {
                            T++;
                        }
                    }

                    if (X == 4 || (X == 3 && T == 1)) {
                        winPlayer = 1;
                        done = 1;
                        break;
                    } else if (O == 4 || (O == 3 && T == 1)) {
                        winPlayer = 2;
                        done = 1;
                        break;
                    }

                    //printf("Right: %d, %d, %d\n", X, O, T);
                }

                //Check Diagonal Right Down
                if (row == 0 && col == 0) {
                    int X = 0;
                    int O = 0;
                    int T = 0;

                    int m = 0;
                    int n = 0;
                    for (m; m < 4; m++, n++) {
                        char c = board[n][m];
                        if (c == 'X') {
                            X++;
                        } else if (c == 'O') {
                            O++;
                        } else if (c == '.') {
                            empty++;
                        } else if (c == 'T') {
                            T++;
                        }
                    }

                    if (X == 4 || (X == 3 && T == 1)) {
                        winPlayer = 1;
                        done = 1;
                        break;
                    } else if (O == 4 || (O == 3 && T == 1)) {
                        winPlayer = 2;
                        done = 1;
                        break;
                    }

                    //printf("Diag 1: %d, %d, %d\n", X, O, T);
                }

                //Check Diagonal Left Down
                if (row == 0 && col == 3) {
                    int X = 0;
                    int O = 0;
                    int T = 0;

                    int m = 3;
                    int n = 0;
                    for (m; m >= 0; n++, m--) {
                        char c = board[n][m];
                        if (c == 'X') {
                            X++;
                        } else if (c == 'O') {
                            O++;
                        } else if (c == '.') {
                            empty++;
                        } else if (c == 'T') {
                            T++;
                        }
                    }

                    if (X == 4 || (X == 3 && T == 1)) {
                        winPlayer = 1;
                        done = 1;
                        break;
                    } else if (O == 4 || (O == 3 && T == 1)) {
                        winPlayer = 2;
                        done = 1;
                        break;
                    }

                    //printf("Diag 2: %d, %d, %d\n", X, O, T);
                }

                //Check Down
                if (row == 0) {
                    int X = 0;
                    int O = 0;
                    int T = 0;

                    int n = 0;
                    for (n; n < 4; n++) {
                        char c = board[n][col];
                        if (c == 'X') {
                            X++;
                        } else if (c == 'O') {
                            O++;
                        } else if (c == '.') {
                            empty++;
                        } else if (c == 'T') {
                            T++;
                        }
                    }

                    if (X == 4 || (X == 3 && T == 1)) {
                        winPlayer = 1;
                        done = 1;
                        break;
                    } else if (O == 4 || (O == 3 && T == 1)) {
                        winPlayer = 2;
                        done = 1;
                        break;
                    }

                    //printf("Down: %d, %d, %d\n", X, O, T);
                }

                //printf("Winner: %d\n", winPlayer);

            }
        }

        if (winPlayer == 1) {
            fprintf(salida, "Case #%d: X won\n", i+1);
        } else if (winPlayer == 2) {
            fprintf(salida, "Case #%d: O won\n", i+1);
        } else if (empty > 0) {
            fprintf(salida, "Case #%d: Game has not completed\n", i+1);
        } else {
            fprintf(salida, "Case #%d: Draw\n", i+1);
        }

        fgets(dumline, 2, archivo);
    }

    return 0;    
}
