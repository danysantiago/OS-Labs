#include<stdio.h>

struct student{
  float gpa;
  char name[50];
       
};

typedef student stud;

int main() {
    stud s[20];

    for (int i = 0; i < 20; i++) {
    	printf("Student #%d:\n", i+1);
	    printf("Please enter the name:");
	    scanf("%s", &s[i].name);
	    printf("Please enter the GPA:");
	    scanf("%d", &s[i].gpa); 
    }

    return 0;
}

