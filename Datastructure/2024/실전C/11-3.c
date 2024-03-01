#include <stdio.h>
#include <string.h>
struct student {//구조체 정의
   int id;
   char name[8];
   double grade;
};

int main(){
    struct student st[3];
    st[1].id = 10; st[0].id = st[1].id;
    st[0].grade = 3.2;

    st[0].id += 20;
    strcpy(st[0].name,"alice");
    st[0].name[0]= 'A';

    printf("id : %d\n",st[0].id);
    printf("name : %s\n",st[0].name);
    printf("grade : %.2f\n",st[0].grade);
}