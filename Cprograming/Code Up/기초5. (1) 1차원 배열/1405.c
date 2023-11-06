#include<stdio.h>
int main(){
    int a,pre=0,end=0;
    int num[100];
    scanf("%d",&a); 
    
    for(int i=0;i<a;i++)scanf("%d",&num[i]);
    for(int i=0;i<a;i++){
        for(int j=pre;j<a;j++)printf("%d ",num[j]);
        for(int k=0;k<end;k++)printf("%d ",num[k]);
        pre ++; end ++; printf("\n");
    }
 
} 
/*

*/