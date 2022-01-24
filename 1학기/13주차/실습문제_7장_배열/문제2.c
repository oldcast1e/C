#include  <stdio.h>
int main(){

    int score[3][2];//3열 2행 배열 선언
    int spn = 0;//줄 띄움 변수 선언
    for(int i=0;i<3;i++){//3번 반복(열)
        for(int j=0;j<2;j++){//2번 반복ㅇ(행)
            scanf("%d",&score[i][j]);//점수를 입력받음
        }
    }
    for(int i=0;i<3;i++){//3번 반복하여
        if(spn!=0) printf("\n\n");//첫번째 출력이 아닌 경우 줄 띄움
        spn ++;//줄띄움 변수
        printf("%d",score[i][0]+score[i][1]);//학생 별 국어 영어 성적의 합을 출력
    }
}

