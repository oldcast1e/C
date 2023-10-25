#include<stdio.h>
int main(){
    
    int Y,M,cnt;
    scanf("%d %d",&Y,&M);//년도를 입력받는다.
    cnt = (Y%4==0 && Y%100!=0 || Y%400==0 ? 1:0); if(M>=8) M ++;
    if(M==2) printf("%d",cnt==1?29:28);
    else  printf("%d",M%2==0?30:31);

    
}

