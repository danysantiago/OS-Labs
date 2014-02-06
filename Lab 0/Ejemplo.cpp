#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void imprimirNombreAlreves(char n[]){
     puts("\nNombre alreves:");
     for(int i=0;i<strlen(n);i++){
        printf("%c",n[strlen(n)-1-i]);
     }    
     puts("");
}

int main(){

    char nombre[50]; //array de 50 caracteres
    int edad;
    printf("Ingrese su nombre:");
    scanf("%s",nombre); //lectura de variable
    
    printf("Ingrese su edad:");
    scanf("%d",&edad);
    
    printf("Nombre:%s  Edad:%d",nombre,edad); //Impresion de variables
    
    imprimirNombreAlreves(nombre); //Lllamado a funcion
    
    system("pause");
    return 0;    
}
