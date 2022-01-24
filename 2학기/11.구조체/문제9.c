#include  <stdio.h>

struct exam{//구조체 정의
    /* data */
    int hs,ls,cl;//구조체 멤버 선언
}ex;//구조체 선언

void *passorfail(struct exam *ex){//구조체 포인터를 인자로 하는 함수 선언

    ex->cl  = ex->hs - ex->ls;//구조체 멤버에 접근하여 값 변경
    return 0;//
}

int main(){//메인 함수

    char score;//패스/논패스 저장 값
    int beforecutline;//변경되지 않은 전의 cl값
    scanf("%d %d %d",&ex.hs,&ex.ls,&ex.cl);//멤버를 입력받음

    beforecutline = ex.cl;//10//멤버 변경 전 저장
    passorfail(&ex);//함수 실행
    if(ex.cl <= beforecutline) score = 'P';//가장 높은 점수와 가장 낮은 점수의 차이가 합격 기준 점수차보다 작거나 같으면 시험 통과
    else score = 'F';//아니면 불통과

    printf("%d %c",ex.cl,score);//결과값 출력


}
/* 
한 학생의 시험 결과 정보
>가장 높은 점수, 
>가장 낮은 점수, 
>합격 기준 점수차=점수차 를 입력 받는다. 

이 학생의 점수차와 시험 통과 여부(P 혹은 F)를 출력하는 프로그램을 작성하시오.
*/

/*시험 통과 여부 판단 방법
- 가장 높은 점수와 가장 낮은 점수의 차이가 합격 기준 점수차보다 작거나 같으면 시험 통과!*/