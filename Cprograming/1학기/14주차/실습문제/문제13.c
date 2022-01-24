#include  <stdio.h>

int arrsum(int *ps,int *pe){

    int *p,sum=0;
    for(p = ps;p<pe;p++){
        printf("%d",*p);
        sum += *p;
    }
    return sum;
}

int main(){
    
    int N,S,E;
    int num[100],*p;
    scanf("%d %d %d",&N,&S,&E);

    int *pn = &N,*ps = &E ,*pe= &S;

    for(p=num;p<num+3;p++){
        scanf("%d",p);
    }
    printf("%d",arrsum(ps,pe));
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

