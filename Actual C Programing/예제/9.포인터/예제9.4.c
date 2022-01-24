#include  <stdio.h>
int main(){
    
    char chr[5] = {'H','E','L','L','O'};
    double dbl[5] ={1.1,2.2,3.3,4.4,5.5};
    printf("%p %c %c\n",chr,chr[0],*chr);
    printf("%p %c %c\n",chr+1,chr[1],*(chr+1));
    printf("%p %c %c\n",chr+2,chr[2],*(chr+2));

    printf("%p %lf %lf\n",dbl,dbl[0],*dbl);
    printf("%p %lf %lf\n",dbl+1,dbl[1],*(dbl+1));
    printf("%p %lf %lf\n",dbl+2,dbl[2],*(dbl+2));
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

