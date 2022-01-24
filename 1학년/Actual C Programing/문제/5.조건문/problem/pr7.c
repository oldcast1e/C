#include<stdio.h>
int main(){
    
    int N,a,b;//3ㅐ의 변수 선언
    scanf("%d",&N);//정답 입력
    scanf("%d",&a);//첫번째 추측 입력
    if(N>a){//정답이 추즉보다 큰 경우
        printf("UP\n");
        scanf("%d",&b);//UP을 출력하고 한번 더 입력을 받음
        if(N>b)
            printf("UP");//정답이 추즉보다 큰 경우
        else if(N<b)
            printf("DOWN");//정답이 추즉보다 작은 경우
        else
            printf("RIGHT");  //맞으면 RIFGT출력
    }
    else if(N<a){//정답이 추즉보다 작은 경우
        printf("DOWN\n");
        scanf("%d",&b);//DOWN을 출력하고 한번 더 입력을 받음
        if(N>b)
            printf("UP");//정답이 추즉보다 큰 경우
        else if(N<b)
            printf("DOWN");//정답이 추즉보다 작은 경우
        else
            printf("RIGHT");//맞으면 RIFGT출력
    }
    else //정답이 추즉과 같은 경우
        printf("RIGHT");//맞으면 RIFGT출력

    }
    

