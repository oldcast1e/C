#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
    char name[7];
    int a,b,c;
    //국 영 수
    /* data */
};


int main(){
    int n; scanf("%d",&n);
    double abs;
    struct student *st = (struct student*)malloc(sizeof(struct student)*n);
    for(int i=0;i<n;i++){scanf("%s %d %d %d",st[i].name,&st[i].a,&st[i].b,&st[i].c);}
    for(int i=0;i<n;i++){
        abs = st[i].a + st[i].b + st[i].c; abs/=3;
        printf("%s %.1f ",st[i].name,abs);
        if(st[i].a >= 90 || st[i].b >= 90  ||st[i].c >= 90 ) printf("GREAT ");
        if(st[i].a < 70 || st[i].b <70  ||st[i].c < 70 ) printf("BAD\n");
    }
    /*- 
    국어, 영어, 수학 성적 중 어느 한 과목이라도 90 이상일 경우 GREAT 출력
    - 국어, 영어, 수학 성적 중 어느 한 과목이라도 70 미만일 경우 BAD 출력*/
    

    
} 
/*
2
Kim 100 82 34 
Young 90 100 99
*/