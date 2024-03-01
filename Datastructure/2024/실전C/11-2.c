#include <stdio.h>
#include <string.h>
struct student {//구조체 정의
   int id;
   char name[8];
   double grade;
};

int main(){
    struct student st1 = {10,"tom",3.2};
    st1.id += 20;
    strcpy(st1.name,"alice");
    st1.name[0]= 'A';

    printf("id : %d\n",st1.id);
    printf("name : %s\n",st1.name);
    printf("grade : %.2f\n",st1.grade);
}