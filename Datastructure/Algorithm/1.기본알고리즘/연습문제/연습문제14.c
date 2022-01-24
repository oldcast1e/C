#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//정수 n을 입력하고 nxn의 정사각형을 만들어라
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("*");
        printf("\n");
    }
}
