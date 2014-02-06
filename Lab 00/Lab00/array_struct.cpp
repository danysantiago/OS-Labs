#include<stdio.h>

#define MAXP 2

struct persona{
  int edad;
  char nombre[50];
       
};
typedef persona per;
int main()
{
    per p[MAXP];
    
    for(int i=0;i<MAXP;i++){
            printf("Please enter the name:");
            scanf("%s",p[i].nombre);
            printf("Please enter the age:");
            scanf("%d",&p[i].edad);        
    }
    
    for(int i=0;i<MAXP;i++){
            printf("Name: %s Edad:%d\n",p[i].nombre,p[i].edad);
    }
    
    return 0;
}

