#include <stdio.h>
#include <stdlib.h>

#define MAXS 20

struct student{
  char name[50];
  float gpa;
       
};

typedef struct student stud;

int comp (const void * e1, const void * e2) {
    stud *s1 = (stud *) e1;
    stud *s2 = (stud *) e2;

    return (int) (s2->gpa - s1->gpa);
}

int main() {
    stud s[MAXS];
    int amount;

    printf("Please enter amount of students:");
    scanf("%d", &amount);

    int i;

    for (i = 0; i < amount; i++) {
    	printf("Student #%d:\n", i+1);
	    printf("Please enter the name:");
	    scanf("%s", s[i].name);
	    printf("Please enter the GPA:");
	    scanf("%f", &s[i].gpa); 
    }

    qsort (s, amount, sizeof(stud), comp);

    for (i = 0 ; i < amount ; i++) {
        printf ("%s - %f\n", s[i].name, s[i].gpa);
    }

    return 0;
}

