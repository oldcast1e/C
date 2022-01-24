#include  <stdio.h>
int main(){
    
    int D[5]={0,};//5개의 배열 선언
    int n,max=-1,bef=-1;//입력받을 정수형 변수 n과 최대,두번째 최대값 선언
    for(int i=0;i<5;i++){
        scanf("%d",&n);//5번 반복하여 값을 입력받고
        D[i] = n;//배열에 저장
    }

    for(int j=0;j<5;j++){
        if(D[j]>=max){//5번 반복 후, 배열과 최대값을 비교
            bef = max;//최대값이면 원래 max값을 bef에 저장하고
            max = D[j];//찾은 최대값을 max에 저장
        }
        else if(max>=bef && bef<=D[j]){//또는 max가 bef보다 크지만 bef보다 큰 요소가 있으면
            bef = D[j];//bef에 저장
        }
    }
    printf("%d\n",max);//결과(최대) 출력 
    printf("%d",bef);//두번째로 큰 값 출력
}


