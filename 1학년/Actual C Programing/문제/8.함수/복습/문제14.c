#include  <stdio.h>
int ip(int x){
    int solst = 1;//소수인경우  
    for(int i=2;i<x;i++) if(x%i==0) solst = 0;
    return solst;
}
int np(int x){
    return ip(x)==1?x:0;
}
int main(){
    int N,M,cnt=0;
    scanf("%d %d",&N,&M);
    while(1){
        if(cnt==M) break;
        if(np(N+1)!=0){
            printf("%d ",N+1);
            cnt++;
        }
        N++;
    }
}
//소수인지 아닌지 확인할라면 소수: 1과 자신만을 약수로 가지는 수
// 15일때 1제외 2~14까지 나눠지는 수가 있으면 소수가 아님
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
