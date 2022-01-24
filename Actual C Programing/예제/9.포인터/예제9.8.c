#include  <stdio.h>

int *smaller(int *P1 ,int *P2 ){

    if(P1>P2) return P1;
    else return P2;
}
int main(){

    int ar[5]= {2,1,3,0,4};
    int *p1;

    p1 = smaller(&ar[1],&ar[3]);
    printf("%d",*p1);

    return 0;
}

