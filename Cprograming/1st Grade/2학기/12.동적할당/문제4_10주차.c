#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct score{//구조체 정의
    char name[8];//이름
    int ls,es,ms;//성적
    float avg;//평균
    /*
◦ 이름: 길이가 1 이상 7 이하인 공백을 포함하지 않는 문자열
◦ 국어 성적, 영어 성적, 수학 성적: 각각 정수형 변수. 성적은 0 이상 100 이하인 정수 
◦ 평균 성적: 실수형 변수
    */
}st;


int main(){//메인함수

    int N;//정수형 변수
    struct score *student = malloc(sizeof(struct score));
    //구조체 동적할당
    scanf("%d",&N);//입력받음

    for(int i=0;i<N;i++){//N번 반복
        
        scanf("%s",student->name);
        scanf("%d %d %d",&student->ls,&student->es,&student->ms);
        //학생의 정보를 입력받음
        student->avg = ((float)student->ls + (float)student->es + (float)student->ms)/3;
        //평균 계산
        printf("%s ",student->name);
        printf("%.1f ",student->avg);//이름과 평균 출력
        if(student->ls>=90 ||student->es>=90 ||student->ms>=90) printf("GREAT ");
        if(student->ls < 70 ||student->es < 70 ||student->ms < 70) printf("BAD\n");
        //GREAT BAD 출력
    }
    

    free(student);//해제


}
/*
GREAT 혹은 BAD는 다음 기준을 적용하여 출력:
◦ 국어, 영어, 수학 성적 중 어느 한 과목이라도 90 이상일 경우 GREAT 출력
◦ 국어, 영어, 수학 성적 중 어느 한 과목이라도 70 미만일 경우 BAD 출력

◦ GREAT 여부가 BAD 여부보다 먼저 출력되며, GREAT과 BAD 모두 출력될 경우 공백으로 구분됨
*/