#include<stdio.h>
int main(){
    int a,cnt=0,num[51]; for(int i=0;i<51;i++)num[i] = -1;scanf("%d",&a);
    for(int i=0;i<a-1;i++) {scanf("%d",&cnt);num[cnt - 1] = cnt;}
    for(int i=0;i<a;i++)if(num[i]==-1){printf("%d",i+1);break;}
} 
