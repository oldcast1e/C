#include  <stdio.h>
int main(){
    
    char str[6][5]={{"ZERO-"},{"ONE--"},{"TWO--"},{"THREE"},{"FOUR-"},{"FIVE-"}};
    //열6개의 5개 행(문자열)의 배열 선언
    int inp[3]={0,},cnt=0;//정수를 입력받을 배열, 줄띄움 변수 선언

    for(int i=0;i<3;i++){//3번 반복하여 
        scanf("%d",&inp[i]);//입력값을 받음
    }
    // printf("%s",str[inp[0]][5]);
    for(int i=0;i<3;i++){//3번 반복하여
        if(cnt!=0)//첫번째 줄이 아니면 줄을 띄우고
            printf("\n");
        cnt++;//줄 띄움 변수 증가
        for(int j=0;j<5;j++){//5번 반복하여
            printf("%c",str[inp[i]][j]);//입력값과 같은 인덱스 값의 문자열 출력
        }
    }


    
}
