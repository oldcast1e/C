#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//1단부터 9단까지의 덧셈표를 작성하라
int main(){
    printf("   |");for(int i=1;i<=9;i++) printf("%3d",i);
    printf("\n");
    for(int k=1;k<=31;k++){
        if(k==4) printf("+");
        else printf("-");
    }printf("\n");
    for(int i=1;i<=9;i++){
        printf(" %d |",i);
        for(int j=1;j<=9;j++){
            printf("%3d",i+j);
        }
        printf("\n");
    }
    // printf("\n");for(int i=1;i<=9;i++) printf("%3d\n",i);
}
