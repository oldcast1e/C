#include  <stdio.h>
int main(){
    
    int num[20],n;//크기가 20인 배열 선언, 입력받을 정수 n선언
    scanf("%d",&n); //n을 입력받음
    for(int i=0;i<n;i++){//n번 반복하여
        scanf("%d",&num[i]);//배열값을 입력받음
    }

    for(int i=n-1;i>=0;i--){//n-1번째 부터 0번째 배열 요소를 
        printf(" %d",num[i]);//출력
    }
}
