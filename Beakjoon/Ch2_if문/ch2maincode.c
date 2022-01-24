#include  <stdio.h>

int main(){

    int A,B;
    scanf("%d %d",&A,&B);
    if(B>=45) printf("%d %d",A,B-45);
    else{
        if(A==0) printf("%d %d",23,60-(45-B));
        else printf("%d %d",A-1,60-(45-B));
    }

}

