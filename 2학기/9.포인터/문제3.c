#include  <stdio.h>
int main(){

    int n,arr[50]={0};//크기가 50인 배열 선언
    int *pnum = arr;//배열의 포인터 선언
    int zerocnt = 0;//0이 나올때까지의 횟수 변수
    scanf("%d",&n);//반복횟수 입력받음
    for(int i=0;i<n;i++){//해당 횟수만큼 반복
        scanf("%d",(pnum+i));
    }
    for(int i=0;i<n;i++){//반복횟수만큼 반복
        if(*(pnum+i)!=0) zerocnt ++;//배열을 확인하여 0이 아니면 zerocnt증가
        if(*(pnum+i)==0) break;//0이 나오면 종료
    }
    printf("%d",zerocnt);//0이 나올때까지의 횟수(결과값)출력


}

