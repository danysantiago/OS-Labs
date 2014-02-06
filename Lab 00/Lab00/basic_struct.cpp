#include<stdio.h>

struct persona{
  int edad;
  char nombre[50];
       
};
typedef persona per;
int main()
{
    per p;
    printf("Please enter the name:");
    scanf("%s",p.nombre);
    
    printf("Please enter the age:");
    scanf("%d",&p.edad);
            
    printf("Name: %s Edad:%d\n",p.nombre,p.edad);

    return 0;
}

