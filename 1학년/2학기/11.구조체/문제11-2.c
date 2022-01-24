#include  <stdio.h>

struct student5{
    char name[9];
    int score;
}*student[5];
struct student5 *sys( struct student5 *pst[5]){

    struct student5 std1,std2,std3,std4,std5;//구조체 변수 선언
    struct student5 *rst;

    int rank[5]={0,0,0,0,0},max=-1,num;

    scanf("%s %d",std1.name,&std1.score);getchar();
    scanf("%s %d",std2.name,&std2.score);getchar();
    scanf("%s %d",std3.name,&std3.score);getchar();
    scanf("%s %d",std4.name,&std4.score);getchar();
    scanf("%s %d",std5.name,&std5.score);

    // printf("%d",std1.score);
    for(int i=0;i<5;i++){
        if(i==0){
            if(std1.score<std2.score) rank[0]++;
            if(std1.score<std3.score) rank[0]++;
            if(std1.score<std4.score) rank[0]++;
            if(std1.score<std5.score) rank[0]++;
        }
        if(i==1){
            if(std2.score<std1.score) rank[1]++;
            if(std2.score<std3.score) rank[1]++;
            if(std2.score<std4.score) rank[1]++;
            if(std2.score<std5.score) rank[1]++;
        }
        if(i==2){
            if(std3.score<std2.score) rank[2]++;
            if(std3.score<std1.score) rank[2]++;
            if(std3.score<std4.score) rank[2]++;
            if(std3.score<std5.score) rank[2]++;
        }
        if(i==3){
            if(std4.score<std2.score) rank[3]++;
            if(std4.score<std3.score) rank[3]++;
            if(std4.score<std1.score) rank[3]++;
            if(std4.score<std5.score) rank[3]++;
        }
        if(i==4){
            if(std5.score<std2.score) rank[4]++;
            if(std5.score<std3.score) rank[4]++;
            if(std5.score<std4.score) rank[4]++;
            if(std5.score<std1.score) rank[4]++;
        }
    }
    for(int i=0;i<5;i++){
        if(max<rank[i]){
            max= rank[i];
            num = i;
        }
    }

    if(num == 0) return &std1;
    // else if(num == 1) return &std2;
    // else if(num == 2) return &std3;
    // else if(num == 3) return &std4;
    // else if(num == 4) return &std5;





    // printf("%s",std1.name);


}


int main(){
    
    struct student5 *rst;
    struct student5 *st[5];
    rst  = sys(&st[5]);


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