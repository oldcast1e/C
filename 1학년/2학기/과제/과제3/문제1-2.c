#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct student{//구조체 정의
    /* data */
    char name[9];//이름 
    char scn[10];//학번
    char score;//점수
    char str_year[5];
    //멤버 선언
}st[5];//구조체 선언


int main(){//메인 함수
    char stname[10];//입력받을 학생의 이름을 저장할 배열
    char samescore,sameyear[5];
    int key = 0;

    for(int i=0;i<5;i++){//5번 반복
        scanf("%s %s %c",st[i].name, st[i].scn, &st[i].score);//정보를 입력받고
        strncpy(st[i].str_year , st[i].scn,4);
        getchar();//엔터값 삭제
    }
    
    scanf("%s",stname);//학생이름을 입력받고
    for(int i=0;i<5;i++){//5번 반복하여 해당 학생 찾고
        if(strcmp(st[i].name,stname)==0){
            samescore = st[i].score;
            strcpy(sameyear,st[i].str_year);
            // printf("find!\n");
            break;
        }
    }
    for(int i=0;i<5;i++){//5번 반복하여 해당 학생 찾고
    //같은 학점
    //같은 입학 년도
        if((st[i].score == samescore)&&(strcmp(st[i].str_year,sameyear)==0)&&(strcmp(st[i].name,stname)!=0)){
            //해당 학생이 아니며 학점과 입학년도가 같으면
            printf("%s ",st[i].name);//이름 출력
            key ++;//조건값 증가
        }
    }
    if(key ==0)printf("%d",0);//해당하는 학생이 없으면
    printf("\n");//엔터
    printf("%s %d",sameyear,atoi(sameyear)%131);//결과출력
   
    





}
/*
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A 
park 2018059961 A 
choi 2018010101 B 
park
*/