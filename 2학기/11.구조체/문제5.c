#include  <stdio.h>
struct system{//구조체 정의
    /* data */
    char name[8],scr;//이름과 성적
    double s1,s2,s3,avg;//각 성적과 평균
};

int SC(int avg){//평균을 인자로 하는 함수 -> 학점 반환
    char rst;//결과값 초기화
    if(avg>=90) rst = 'A';//90이상일때 A
    else if(avg>=80) rst = 'B';//80이상일때 B
    else if(avg>=70) rst = 'C';//70이상일때 C
    else rst = 'D';//아무것도 만족하지 않은 경우 D

    return rst;//학점 반환
}
int main(){//메인 함수
    int N;//입력받을 정수형 변수 선언
    double sum=0,avg;//합과 평균 변수 선언
    char score;//학점 선언
    struct system sys[50],*pst = sys;//구조체 선언
    scanf("%d",&N);//정수를 입력받고
    for(int i=0;i<N;i++){//N번 반복
        scanf("%s %lf %lf %lf",(pst+i)->name,&(pst+i)->s1,&(pst+i)->s2,&(pst+i)->s3);//구조체의 멤버를 입력받음
        sum = 0;//합 초기화
        sum += (pst+i)->s1 + (pst+i)->s2 + (pst+i)->s3;//총합
        (pst+i)->avg = sum/3;//평균값 저장
        (pst+i)->scr= SC((pst+i)->avg);//학점 저장
    }

    for(int i=0;i<N;i++){//N번 반복하여
        printf("%s %.1lf %c\n",(pst+i)->name, (pst+i)->avg, (pst+i)->scr);//구조체의 멤버를 출력
    }


}