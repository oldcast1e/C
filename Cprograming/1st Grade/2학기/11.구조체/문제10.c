#include  <stdio.h>
struct year{//구조체 정의
    /* data */
    int y,m,d;//년,월,일
}y1,y2;//구조체 선언

struct year *select_min(struct year *y1,struct year *y2){//함수 정의

    struct year *rst;//결과값 = 결과 구조체 주소 저장
    if(y1->y < y2->y ) rst = y1;//구조체 1의 년도가 구조체 2의년도 보다 빠른 경우 결과값에 1의 구조체 저장
    else if(y1->y > y2->y ) rst = y2;//구조체 1의 년도가 구조체 2의년도 보다 느린 경우 결과값에 2의 구조체 저장
    else{//년도 같은 경우
        if(y1->m < y2->m) rst = y1;//1이 2보다 달이 빠른 경우
        else if(y1->m > y2->m) rst = y2;////2가 1보다 달이 빠른 경우
        else{//월이 같은 경우
            if(y1->d < y2->d) rst = y1;//1이 2보다 일이 빠른 경우
            else if(y1->d >= y2->d) rst = y2;//일이 같거나 2가 1보다 빠른 경우
        }
    }
    return rst;//구조체 반환
}

int main(){//메인함수
    scanf("%d/%d/%d",&y1.y,&y1.m,&y1.d);//구조체 입력1
    scanf("%d/%d/%d",&y2.y,&y2.m,&y2.d);//구조체 입력2
    struct year *result =  select_min(&y1,&y2);//함수 실행 및 저장
    printf("%d/%d/%d",result->y,result->m,result->d);//결과 출력
}
// year/month/day 형식의 두 날짜를 입력 받아, 각각 구조체 변수에 저장하고, 두 날짜 중 더 빠른 날짜를 같은 형식으로 출력하는 프로그램을 작성 하시오.
//- 함수 select_min()을 다음과 같이 작성하여 사용 하시오.
//◦ 인자: 두 개의 구조체 변수의 주소 (포인터)
//◦ 반환 값: 두 날짜 중 더 빠른 날짜를 나타내는 구조체 변수의 주소 (값이 아님)
//- 입력과 출력은 main() 함수에서 실행된다.