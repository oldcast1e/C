#include  <stdio.h>
void print_line(int x,int y,int z){
    for(int i=0;i<x;i++)printf(" ");
    for(int i=0;i<2*y-1;i++)printf("*");
    for(int i=0;i<z;i++)printf(" ");
}

int main(){
    int n,x,y,z;
    scanf("%d",&n);
    for(int i=1;i<=5;i++){
        x = n-i;y=i;z=x;
        print_line(x,y,z);
        printf("\n");
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
