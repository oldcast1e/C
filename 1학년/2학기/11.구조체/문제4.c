#include  <stdio.h>
struct system{//구조체 정의
    /* data */
    char name[19];//이름
    double ex1,ex2,ex3;//세 과목의 점수
}sys;//구조체 변수 선언

int main(){
    int N;//학생 수
    double avg;//평균
    char rank;//학점
    scanf("%d",&N);//학생 수를 입력받음
    for(int i=0;i<N;i++){//학생 수만큼 반복
        scanf("%s %lf %lf %lf",sys.name,&sys.ex1,&sys.ex2,&sys.ex3);
        //이름과 각 과목의 점수를 입력받음
        avg = (sys.ex1 + sys.ex2 + sys.ex3)/3;//평균

        if(avg>=90) rank = 'A';//90점이상ㅇ A
        else if(avg>=80) rank = 'B';
        else if(avg>=70) rank = 'C';//70이상 C
        else rank = 'F';
        printf("%s %.1lf %c\n",sys.name,avg,rank);//이름과 평균, 학점 출력
    }


}