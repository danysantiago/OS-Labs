#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    char text[10000];
    int cases;
    int i;
    int length;
    int is_square = 0;
    int square;
    int row;
    int col;
    char dummy;

	scanf("%d%c",&cases, &dummy);

	for(i = 0; i < cases; i++) {
		scanf("%[^\n]%c", text, &dummy);

		length = strlen(text);
		square = sqrt(length);

    	if (square*square != length) {
    		printf("INVALID\n");
    		continue;
    	}

    	for (col = 0; col < square; col++) {
    		for (row = 0; row < square; row++) {
    			printf("%c", text[col + row*square]);
    		}
    	}

    	printf("\n");
	}

    return 0;    
}