#include<stdio.h>

int main(){
    char L[1009];
    int N;
    FILE *archivo,*salida;
    archivo = fopen("entrada.txt","r");
    salida = fopen("salida.txt","w");
    
    if(archivo == 0){
        printf("archivo no existe");
        getchar();
        getchar();
        return 0;
    }    
    fscanf(archivo,"%d",&N);
    fgets(L,100,archivo); 
    for(int i=0;i<N;i++){
            fgets(L,100,archivo); 
            fprintf(salida,"linea %d: %s\n",i,L);       
    }
    fclose(salida);
    getchar();
    getchar();
    return 0;
}
