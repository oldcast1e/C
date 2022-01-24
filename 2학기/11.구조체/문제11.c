#include  <stdio.h>

struct student5{
    /* data */
    char name[9];
    int score;
}student;
struct student5 *sys( struct student5 *student){

    int max  = 101;
    struct student5 *rst;

    struct student5 st[5],*pst  = st;
    for(int i=0;i<5;i++){
        scanf("%s %d",(pst+i)->name,&(pst+i)->score);
    }
    for(int i=0;i<5;i++){
        if(max>(pst+i)->score){
            max = (pst+i)->score;
            rst = (pst+i);
            printf("-");
        }
    }

    return rst;
}


int main(){
    struct student5 *result = sys(&student);
    printf("%s",result->name);


}
/*
5명 학생의 이름과 기말고사 점수를 입력 받아, 구조체 배열에 저장 한 후, 기말고사 점수가 최하위인 학생의 이름과 점수를 출력하는 프로그램을 작성 하시오.
- 함수 select_min()을 다음과 같이 작성하여 사용 하시오.
◦ 인자: 구조체 배열의 주소 (포인터)
◦ 반환 값: 기말고사 점수가 최하위인 구조체 배열 원소의 주소 (값이 아님)

- 학생의 이름은 공백 없이 최대 길이가 9인 영어 문자열이다.
- 기말고사점수는 0과 100사이의 정수이다.
- 같은 점수의 학생은 없다고 가정한다.

*/
/*
akim 75 
bkim 85 
ckim 65 
dkim 95 
ekim 100
*/