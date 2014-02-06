#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *s1, char *s2) {
	unsigned long largo = strlen(s1) + strlen(s2) + 1;
	char *result = malloc(largo); //+1 for the zero-terminator
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

int main(){

    FILE *archivo, *salida;
    archivo = fopen("entrada.txt","r");
    salida = fopen("salida.txt","w");

	char text[1009];
	int cases;
	int delimeters;
	int length;
	int i;
	char *split;
	char dummy;
	char *result;
	int count = 0;

	fscanf(archivo,"%d",&cases);
	fgets(text, 1000, archivo); 
	for(i = 0; i < cases; i++) {
		fgets(text, 1000, archivo);
		//fprintf(salida,"linea %d: %s\n",i,text);

		//printf("%s", text);   

		strtok(text, "\r");
		strtok(text, "\n");

		result = malloc(0);

		split = strtok (text, " ");
		while (split != NULL) {
			//printf("%s\n", split);
			result = concat(split, result);
			result = concat(" ", result);
			split = strtok (NULL, " ");
		}

		fprintf(salida, "Case #%d:%s\n", (i+1), result);
		free(result);
	}

	fclose(salida);

    return 0;    
}