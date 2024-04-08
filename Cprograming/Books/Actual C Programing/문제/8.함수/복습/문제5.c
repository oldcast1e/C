#include  <stdio.h>
void print_triangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++) printf("*");
        printf("\n");
    }
}
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n<=0) break;
        print_triangle(n);
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

