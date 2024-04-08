#include<stdio.h>
int main(){

    int n,m,k;
    int N,M,K;
    int b=0,s=0;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d %d",&N,&M,&K);
    
    if(N==n)
        s+=1;
    else if(N == m)
        b+=1;  
    else if(N ==k)
        b+=1;

    if(M==m)
        s+=1;
    else if(M == n)
        b+=1;  
    else if(M ==k)
        b+=1;

    if(K==k)
        s+=1;
    else if(K == n)
        b+=1;  
    else if(K ==m)
        b+=1;



    printf("%dS%dB",s,b);


}