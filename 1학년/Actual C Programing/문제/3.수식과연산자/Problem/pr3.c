#include<stdio.h>
int main(){

    int h1,m1,s1,h2,m2,s2,T1,T2,T,H,M,S;
    scanf("%d %d %d",&h1,&m1,&s1);
    scanf("%d %d %d",&h2,&m2,&s2);
    T1 = h1*3600 + m1*60 + s1;
    T2 = h2*3600 + m2*60 + s2;
    T = T2- T1;
    H = T/3600;
    M = T/60%60;
    S = T%60;
    printf("%d %d %d",H,M,S);

    
}