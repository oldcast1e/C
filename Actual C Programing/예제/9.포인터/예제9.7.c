#include  <stdio.h>
int main(){
    
    int ar[5]={2,3,5,7,-1};
    int i,*p;

    p = ar;
    for(int i=0;i<5;i++){
        printf("%d\n",*(p+i));
    }

    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

