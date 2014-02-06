#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	unsigned long num1;
    unsigned long num2;

    while(scanf("%lu%lu", &num1, &num2) != EOF) {

    	unsigned long result;

    	if(num2 >= num1) {
    		result = num2 - num1;
    	} else {
    		result = num1 - num2;
    	}

        printf("%lu\n" , result);

    }

    return 0;    
}
