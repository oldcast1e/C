#include  <stdio.h>
int main(){
    
    int n,num[10],cnt=0;//입력받을 숫자 n과 크기 10의 배열 num과 줄띄움 변수 cnt 선언
    char str[10],u;//char형 배열과 해당 인덱스의 요소를 저장할 변수 u
    scanf("%d",&n);//반복횟수 입력
    getchar();//스페이스키 입력 제거

    for(int i=0;i<n;i++){//n번 반복
        scanf("%c",&str[i]);//char배열에 입력
    }
    for(int i=0;i<n;i++){//n번 반복
        scanf("%d",&num[i]);//숫자 배열에 입력
    }

    for(int i=0;i<n;i++){//n번 반복하여
        u = str[num[i]%n];//i 번째 숫자와 n을 나눈 인덱스의 요소를 저장
        if(cnt!=0)//첫번째 반복을 제외하고 줄띄움
            printf("\n");
        cnt++;//cnt증가
        printf("x[%d%%%d]=x[%d]=%c",num[i],n,num[i]%n,u);//i번째 숫자,n,i번째 숫자%n 인덱스의 문자 출력
    }
    return 0;
}
