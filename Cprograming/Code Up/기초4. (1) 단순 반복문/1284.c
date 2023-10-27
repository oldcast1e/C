#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        cnt = 0;
        for(int j=1;j<=i;j++) if(i%j==0)cnt++;
        if(cnt==2){
            printf(">>확인된 소수: %d\n",i);
        }
    }
    
 
} 