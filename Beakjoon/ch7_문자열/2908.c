#include  <stdio.h>
int main(){
    char arr[8],num1[3],num2[3];
    int rst1=0,rst2=0;
    int R1[3],R2[3];
    for(int i=0;i<7;i++){
        scanf("%c",&arr[i]);
        if(i<3)R1[i] = arr[i]-48;
        else if(i>3)R2[i-4] = arr[i]-48;
    }
    for(int i=2;i>=0;i--){
        rst1+=R1[i];if(i>0)rst1 *=10;
        rst2+=R2[i];if(i>0)rst2 *=10;
    }
    printf("%d",rst1>rst2?rst1:rst2);
}

