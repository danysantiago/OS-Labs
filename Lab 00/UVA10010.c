#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 10000

char MATRIX[MAXN][51];
char WORD[55];
int M,N,R,C;

int Right(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(WORD[i] != MATRIX[r][c++])
            return 0;
    }

    R = r;
    C = c-1;
    return 1;
}

int Left(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(c < 0)
            return 0;

        if(WORD[i] != MATRIX[r][c--])
            return 0;
    }

    R = r;
    C = c+1;
    return 1;
}

int Down(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++)  {
        if(r >= M)
            return 0;

        if(WORD[i] != MATRIX[r++][c])
            return 0;
    }

    R = r-1;
    C = c;
    return 1;
}

int Up(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(r < 0)
            return 0;

        if(WORD[i] != MATRIX[r--][c])
            return 0;
    }

    R = r+1;
    C = c;
    return 1;
}

int DiagNW(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(r < 0 || c < 0)
            return 0;

        if(WORD[i] != MATRIX[r--][c--])
            return 0;
    }

    R = r+1;
    C = c+1;
    return 1;
}

int DiagNE(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(r < 0 || c >= N)
            return 0;
        if(WORD[i] != MATRIX[r--][c++])
            return 0;
    }

    R = r+1;
    C = r-1;
    return 1;
}

int DiagSE(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(r >= M ||c >= N)
            return 0;
        if(WORD[i] != MATRIX[r++][c++])
            return 0;
    }

    R = r-1;
    C = c-1;
    return 1;
}

int DiagSW(int r,int c) {
    int i,j;
    
    for(i = 0; WORD[i]; i ++) {
        if(r >= M || c < 0)
            return 0;

        if(WORD[i] != MATRIX[r++][c--])
            return 0;
    }

    R = r-1;
    C = c+1;
    return 1;
}

int verify(int r,int c) {
    
    if(Right(r,c))
        return 1;
    else if(Left(r,c))
        return 1;
    else if(Down(r,c))
        return 1;
    else if(Up(r,c))
        return 1;
    else if(DiagNW(r,c))
        return 1;
    else if(DiagNE(r,c))
        return 1;
    else if(DiagSE(r,c))
        return 1;
    else if(DiagSW(r,c))
        return 1;
    return 0;
}

int solve() {
    
    int p,q;
    for(p = 0; p < M; p++) {
        for(q =0; q < N; q++) {
            if(WORD[0] == MATRIX[p][q]) {
                if(verify(p,q)) {
                    goto done;
                }
            }
        }
    }
    
    done:
    printf("%d %d\n",p+1,q+1);
    
    return;
}

int main() {

    int cases;
    int caseNum, i, j;
    char dummy;
    char dumm[2];

    int x, y;
    int words;

    scanf("%d%c", &cases, &dummy);

    scanf("%c", &dummy);

    for(caseNum = 0; caseNum < cases; caseNum++) {
        scanf("%d %d%c",&M,&N, &dummy);


        for(x = 0; x < M; x++) {
            scanf("%s", MATRIX[x]);


            for (y = 0; y < N; y++) {
                MATRIX[x][y] = tolower(MATRIX[x][y]);
            }

        }

        scanf("%d%c", &words, &dummy);

        for(i = 0; i < words; i++) {
            scanf("%s", WORD);

            for(j = 0; j < strlen(WORD); j++) {
                WORD[j] = tolower(WORD[j]);
            }

            solve();
        }

        if (caseNum < cases - 1) {
            printf("\n");
        }

        scanf("%c", &dummy);
    }



    return 0;
}