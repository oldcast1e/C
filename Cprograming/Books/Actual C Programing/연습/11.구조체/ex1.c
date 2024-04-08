#include  <stdio.h>
struct student
{
    /* data */
    int id;
    char name[30];
    int grade;
};


int main(){

    struct student str = {21011898,"heonseong",1};
    printf("%d %s %d",str.id,str.name,str.grade);

}