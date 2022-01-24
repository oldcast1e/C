#include  <stdio.h>
int main(){

    int a,b,c;
    int cnt=0;//첫번째 출력 빼고 나머지 출력에서 줄띄움 후 출력
    scanf("%d %d %d",&a,&b,&c);
    if(a+b==c){
        if(cnt!=0)
            printf("\n");
        printf("+");
        cnt++;
    }    
    if(a-b==c){
        if(cnt!=0)
            printf("\n");
        printf("-");
        cnt++;
    }    
    if(a*b==c){
        if(cnt!=0)
            printf("\n");
        printf("*");
        cnt++;
    }
    if(a/b==c){
        if(cnt!=0)
            printf("\n");
        printf("/");
        cnt++;
    }
        

    
}