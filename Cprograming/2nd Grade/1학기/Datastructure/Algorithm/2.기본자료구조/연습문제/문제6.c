#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*배열의 맨 앞쪽에 윗자리가 아니라 아랫자리를 저장하는 프로그램을 작성하라
(처음만든 코드가 코드 맨 앞자리에 윗자리를 저장하는 코드여서 문제바꿈)
*/
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)
//배열 요소를 역순으로 정렬하는 과정을 일일히 출력하는 프로그램을 작성하라

void reverse(char *rst){
    int rep = (int)strlen(rst),tmp;
    for(int i=0;i<rep/2;i++)swap(tmp,rst[i],rst[rep - i -1]);
}

int card_convr(unsigned x,int n,char arr[]){
    /**
     x: 바꾸고자하는 진수
     n: 입력받은 숫자(진수 변환할 숫자)
     arr: 배열이름
     */
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPRSTUVWXYZ";
    int digits = 0;
    if(x == 0)arr[digits++] = dchar[0];
    else
        while(x){
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

    reverse(arr);
    printf("변환된 값을 출력합니다: ");
    for(int i=0;i<rep;i++)printf("%c",arr[i]);


}
