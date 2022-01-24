#include  <stdio.h>
struct student//구조체 정의
{
    /* data */
    char name[9];//이름
    int score;//점수
};

int main(){
    struct student std1,std2,std3,std4,std5;//구조체 변수 선언
    scanf("%s %d",std1.name,&std1.score);getchar();//이름과 점수 입력받음
    scanf("%s %d",std2.name,&std2.score);getchar();//이름과 점수 입력받음
    scanf("%s %d",std3.name,&std3.score);getchar();//이름과 점수 입력받음
    scanf("%s %d",std4.name,&std4.score);getchar();//이름과 점수 입력받음
    scanf("%s %d",std5.name,&std5.score);//이름과 점수 입력받음

    int avg = (std1.score+std2.score+std3.score+std4.score+std5.score)/5;
    //평균내기
    // printf("%d",avg);
    if(avg>=std1.score)printf("%s\n",std1.name);//평균보다 해당 학생의 점수가 작거나 같으면 이름출력
    if(avg>=std2.score)printf("%s\n",std2.name);
    if(avg>=std3.score)printf("%s\n",std3.name);//평균보다 해당 학생의 점수가 작거나 같으면 이름출력
    if(avg>=std4.score)printf("%s\n",std4.name);
    if(avg>=std5.score)printf("%s\n",std5.name);//평균보다 해당 학생의 점수가 작거나 같으면 이름출력


}
//akim 75 
// bkim 85 
// ckim 65 
// dkim 95 
// ekim 100