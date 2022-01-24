#include<stdio.h>
int main(){

    int n,k=1;//정수와 임의의 변수 k선언(오름차순으로 출력이므로)
    scanf("%d",&n);//정수를 입력받음
    while(k<=n){//k가 n보다 작을때 반복

        if(n%k==0){//k가 n의 약수인경우 출력
            printf("%d ",k);
        }
        k+=1;//k값 증가
    }

}
//마지막 공백 없음
