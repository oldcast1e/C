#include  <stdio.h>
int main(){
    
    int N[10];//크기가 10인 배열 선언
    for(int i=0;i<10;i++){//10번 반복하여 
        scanf("%d",&N[i]);//입력을 받음
    }

    for(int i=0;i<10;i++){//10번 반복하여
        if(N[i]%2==0)//해당 요소가 2로 나눠떨어지면(짝수이면)
            printf(" %d",N[i]);//출력
    }
    return 0;
}
