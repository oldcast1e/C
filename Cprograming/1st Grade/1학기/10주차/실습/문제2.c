#include  <stdio.h>
int main(){
    
    int N[10],sum=0;//크기가 10인 배열 선언
    for(int i=0;i<10;i++){//10번 반복하여 
        scanf("%d",&N[i]);//입력을 받음
    }

    for(int i=0;i<10;i++){//10번 반복하여
        sum += N[i];//sum에 해당 요소를 더함
    }
    printf("%d",sum);//합 출력
    return 0;
}
