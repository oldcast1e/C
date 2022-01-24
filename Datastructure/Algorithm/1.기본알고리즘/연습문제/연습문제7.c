#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//n이 7이면 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 로 출력하는 프로그램 
int main(){
    int rst=0,n;
    puts("1부터 n까지의 합을 구합니다.");
    printf("n값 입력: "); scanf("%d",&n);
    for(int i=1;i<=n;i++)rst += i;
    for(int i=1;i<=n;i++){
        printf("%d ",i);
        if(i!=n) printf("+ ");
    }
    printf("= %d",rst);
    
}
