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
    int N,len,y,x;
    scanf("%d",&N);getchar();
    char info[4][100]={0};
    char str[101];
    struct student *st = NULL;
    st = (struct student*)malloc(N*sizeof(struct student));

    for(int i = 0;i<N;i++){
        gets(str);
        len = strlen(str);
        x=0;y = 0;
        for(int j=0;j<len;j++){
            if(str[j]==' '){
                y++;
                x=0;
            }
            else{
                info[y][x] = str[j];
                x++;
            }
        }
        printf("%d | %d\n",(int)strlen(info[0]),(int)strlen(info[2]));
    }

    

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