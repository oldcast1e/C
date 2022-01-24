#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{
    char *studentName;
    char id[5];
    char *subjectName;
    double subjectScore; // 과목 점수
    };
int main(){

    int N,K;
    char name[100]={},subject[100]={};
    scanf("%d",&N);
    getchar();
    struct student *st = malloc(sizeof(struct student)*N);

    for(int i=0;i<N;i++){
        scanf("%s",name); getchar();
        st[i].studentName = (char*)malloc(sizeof(char*)*strlen(name));
        strcpy( st[i].studentName,name);
        
        scanf("%s",st[i].id); getchar();
        
        scanf("%s",subject); 
        st[i].subjectName = (char*)malloc(sizeof(char*)*strlen(subject));
        strcpy( st[i].subjectName,subject);

        scanf("%lf",&st[i].subjectScore);
        if(i!= (N-1))getchar();

    }
    scanf("%d",&K);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j){
                if(st[i].subjectScore > st[j].subjectScore ){
                    struct student tmp;
                    tmp = st[i];
                    st[i] = st[j];
                    st[j] = tmp;
                }
            }
        }
    }
    printf("%s %s %s %.2lf",st[K-1].studentName,st[K-1].id,st[K-1].subjectName,st[K-1].subjectScore);

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