#include  <stdio.h>
int sum(int n){
    int tot = n*(n+1)/2;
    return tot;
}
int main(){
    int n,rst= 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        rst += sum(i);
    }
    printf("%d",rst);
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

