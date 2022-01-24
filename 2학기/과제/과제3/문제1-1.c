#include  <stdio.h>
#include  <string.h>

struct student{//구조체 정의
    /* data */
    char name[9];//이름 
    int scn;//학번
    char score;//점수
    //멤버 선언
}st[5];//구조체 선언


int main(){//메인 함수
    char stname[10];//입력받을 학생의 이름을 저장할 배열
    for(int i=0;i<5;i++){//5번 반복
        scanf("%s %d %c",st[i].name,&st[i].scn,&st[i].score);//정보를 입력받고
        getchar();//엔터값 삭제
    }
    
    scanf("%s",stname);//학생이름을 입력받고
    for(int i=0;i<5;i++){//5번 반복하여 해당 학생 찾고
        if(strcmp(st[i].name,stname)==0)printf(" %d %c",st[i].scn,st[i].score);//출력
    }



}
/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A 
choi 2018010101 F 
lee3 2019565656 B
*/