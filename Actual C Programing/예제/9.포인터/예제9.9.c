#include  <stdio.h>
int main(){

    int a1[5]={4,5,6,7,8},a2[5]={1,3,5,7,9},a3[5]={0,2,4,6,8};
    int *p[3];

    p[0] = &a1[0];
    p[1] = &a2[0]; 
    p[2] = &a3[0];

    for(int i=0;i<3;i++){
        printf("%p %d\n",p[i],*p[i]);
    }


}

