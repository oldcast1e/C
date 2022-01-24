#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{
    char *studentName;
    char id[5];
    char *subjectName;
    double subjectScore; // 과목 점수
};
void reset(char *str){
    for(int i=0;i<101;i++){
        str[i] = '\0';
    }
}
int main(){
    int number,select,len,space;
    int namenum,subjectnum;
    char info[101]={};
    scanf("%d",&number); getchar();
    struct student *st = NULL;
    st = (struct student*)malloc(number*sizeof(struct student));

    for(int i=0;i<number;i++){
        reset(info);
        gets(info);
        len = strlen(info); space = 0;
        namenum=0;subjectnum = 0;
        printf("len[%d] = %d\n",i,len);
        for(int j=0;j<len;j++){
            if(info[j] == ' ')space ++;

            if(space == 0 && info[j] != ' ')namenum ++;
            else if((space == 2) && info[j] != ' ')subjectnum++;
        }
        st[i].studentName = (char *)malloc(sizeof(char)*namenum);
        st[i].subjectName = (char *)malloc(sizeof(char)*subjectnum);
        printf("namenum[%d] = %d | subjectnum[%d] = %d\n",i,namenum,i,subjectnum);
    }
    scanf("%d",&select);

    

}
/*
5
HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 50
Euler 1005 Math 100 
2
*/