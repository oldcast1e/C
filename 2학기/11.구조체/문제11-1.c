#include  <stdio.h>
struct student5{
    char name[9];
    int score;
}stp[5];

struct student5 *sys( struct student5 *stp){

    struct student5 *rst;
    int min = (stp+0)->score;
    // struct student5 *st[5];
    // for(int i=0;i<5;i++){
    //     st[i] = (student+i);
    //     printf("<1>");
    // }
    // for(int i=0;i<5;i++){
    //     scanf("%s %d",st[i]->name,&st[i]->score);
    //     printf("<2>");
    // }
    for(int i=0;i<5;i++){
        if(min > (stp+i)->score){
            min = (stp+i)->score;
            rst = (stp+i);
        }
    }
    return rst;
}


int main(){

    struct student5 *stu = &stp[5];
    
    struct student5 *rst;

    for(int i=0;i<5;i++){
        scanf("%s %d",(stu+i)->name,&(stu+i)->score);
    }
    rst = sys(stu);
    printf("%s %d",rst->name,rst->score);
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