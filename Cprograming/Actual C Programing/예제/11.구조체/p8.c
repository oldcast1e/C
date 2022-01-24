#include  <stdio.h>
struct student7{
    /* data */
    int id;
    char name[8];
    double grade;

    struct student7 *roommate;
    struct student7 *friends[3];
    
};

int main(){

    struct student7 st1 = { 10,"Tom",3.2};
    struct student7 st2 = { 11,"Sam",4.3};
    struct student7 st3 = { 5,"Mary",4.0};

    st1.friends[0] = &st2;
    st1.friends[1] = &st3;

    printf("%s과 %s는 %s의 친구입니다.",st1.friends[0]->name,st1.friends[1]->name,st1.name);



}