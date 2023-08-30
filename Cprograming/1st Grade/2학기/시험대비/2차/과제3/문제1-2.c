#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{
    /* data */
    char name[10];
    char schoolnum[11];
    char score;
}st[5];
int main(){
    char info[10],sc;
    char year[5],tmpyear[5];
    for(int k=0;k<5;k++)year[k] = '\0';
    int key = 0;
    for(int i=0;i<5;i++)
        scanf("%s %s %c",st[i].name,st[i].schoolnum,&st[i].score);getchar();
    //찾고자 하는 학생의 이름을 입력
    //이 학생과 같은 학점을 받은 
    //->입학년도가 같은 다른 학생들의 이름을 (입력 순서대로) 첫 줄에 모두 출력
    scanf("%s",info);
    for(int i=0;i<5;i++){
        if(strcmp(st[i].name,info)==0){
            sc = st[i].score;
            strncpy(year,st[i].schoolnum,4);
            break;
        }
    }

    for(int i=0;i<5;i++){
        if(strcmp(st[i].name,info)!=0){
            for(int k=0;k<5;k++)tmpyear[k] = '\0';
            strncpy(tmpyear,st[i].schoolnum,4);
            // printf("tmpyear = %s\n",tmpyear);
            if(sc == st[i].score && (strcmp(tmpyear,year)==0) ){printf("%s ",st[i].name);key ++;}
        }
    }
    if(key == 0) printf("0\n");
    else printf("\n");
    printf("%s %d",year,atoi(year)%131);


}
/**
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A
park 2018059961 A
choi 2018010101 B
park

lee1 2019102656 B
lee2 2019111823 B
park 2019123456 A
choi 2019010101 F
lee3 2019565656 B
park
 * 
 */