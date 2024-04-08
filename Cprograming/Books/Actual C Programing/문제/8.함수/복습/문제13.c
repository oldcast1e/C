#include  <stdio.h>
int c3(int n){
    int tot = 0;
    while(n>0){
        if(n%10==3) tot += 1;
        n/=10;
    }
    return tot;
}

int main(){
    int n,rst = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)rst += c3(i);
    printf("%d",rst);
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
