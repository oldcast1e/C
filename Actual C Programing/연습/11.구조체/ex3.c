#include  <stdio.h>
#include <string.h>
struct student{
    /* data */
    char name[30],id[30];
    int schoolnumber,grade;
};

int main(){
    struct student str[3]={{},{},{}};
    str[0].id = "Hello";
    printf("%s\n",str[0].id);

    strcpy(str[0].id,"Sejong");
    str[1].schoolnumber = 21;
    printf("%s\n",str[0].id);
    printf("%d",str[1].schoolnumber);


}