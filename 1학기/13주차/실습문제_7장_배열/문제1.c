#include  <stdio.h>
int main(){

    int n[3][3];//3x3배열 초기화
    for(int i=0;i<3;i++){//3번 반복(열)
        for(int j=0;j<3;j++){//3번 반복(행)
            scanf("%d",&n[i][j]);//배열 값 입력받음
        }
        
    }
    int sum = 0;//대각선 원소의 합 초기화
    for(int i=0;i<3;i++){//3번 반복
        if(i==0) sum += n[i][0];//i=1일때 첫번째 요소 더함
        else if(i==1) sum += n[i][1];//i=1 일때 두번째 요소더함
        else if(i==2)sum += n[i][2];//i=2일때  세번째 요소 더함 

    }
    printf("%d",sum);//결과값 출력

}

