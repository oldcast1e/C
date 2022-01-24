#include  <stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);//5
    int cnt = 0;
    int cnt2;
    while(n>0){
        for(int i=(n*2-1);i>0;i--){
            printf("*");
        }
        printf("\n");
        n--;
        cnt +=1;
        cnt2 = cnt;
        while(cnt2>0){
            printf(" ");
            cnt2 --;
        }
        
    }


}