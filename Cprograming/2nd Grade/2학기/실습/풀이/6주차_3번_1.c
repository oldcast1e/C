#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,cnt,ans,middle;
    char bin[100];
    scanf("%d %d %d",&a,&b,&cnt); getchar();
    scanf("%s",bin); getchar();
    // a,b는 양의 정수
    /*
    친구는 세종이에게 k > m 인지, Y(예)/N(아니오)으로 알려준다.
    (여기서 m은 a와 b사이의 중s간값으로, m =(a + b)/2이다. 는 내림 기호)
    - 답이 Y인 경우, m + 1 ≤ k ≤ b 이므로 a의 값을 m + 1로 바꾼다.
    답이 N인 경우, a ≤ k ≤ m 이므로 b를 m으로 바꾼다.
    - 위 과정을 a와 b가 같을 때까지 반복한다.
    */
    for(int i=0;i<cnt;i++){

        middle = (a+b)/2; 
        if(bin[i] == 'Y'){
            a = middle + 1;
            // b = (a + b)/2;
            // printf("Y %d %d\n",a,b);
        }
        if(bin[i] == 'N'){
            b = middle;
            // a = (a + b)/2;
            // printf("N %d %d\n",a,b);
        }
    }
    printf("%d",b);
}
/*
10 20 3
NNY

1 1000 10
NYYNYNYYNY
*/