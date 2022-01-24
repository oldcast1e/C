#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int card_convr(unsigned x,int n,char arr[]){
    /**
     n: 바꾸고자하는 진수
     x: 입력받은 숫자(진수 변환할 숫자)
     arr: 배열이름
     */
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPRSTUVWXYZ";
    int digits = 0;
    if(x == 0)arr[digits++] = dchar[0];
    else
        while(x){
            printf("%d|%6d ... %d\n",n,x,x%n);
            printf(" +------\n");
            arr[digits ++] = dchar[x%n];
            x/=n;
        }
    return digits;
}

int main(){
    int x,n,rep;
    char arr[37]={0};
    printf("10진수를 기수변환합니다.\n변환할 숫자를 입력하세요: ");scanf("%d",&x);
    do{printf("변환할 기수를 입력하세요(2-36): ");scanf("%d",&n);}while(n<2 || n>36);
    rep = card_convr(x,n,arr);

    // printf(">%d",rep);
    printf("변환된 값을 출력합니다: ");
    for(int i=rep-1;i>=0;i--)printf("%c",arr[i]);


}