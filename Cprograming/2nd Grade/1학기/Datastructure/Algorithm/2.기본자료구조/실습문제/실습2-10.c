#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*소수의 나열 - 알고리즘2-1 배열 버전

*/
int main(){
    int i,n,prime[500],cnt=0,prt=0;
    //prt: 소수의 개수-1 == 소수를 저장하는 배열의 인덱스
    //cnt: 계산 횟수
    prime[prt++] = 2;//prime의 첫번째 요소에 저장 후 인덱스 증가
    for(n=3;n<=1000;n+=2){
        /**
        n을 3부터 하는 이유는 소수를 저장하는 배열인 prime의 첫번째 요소가 2이기 때문
        따라서 prime과 비교하는 모두 짝수는 이미 소수가 아니다. 그러므로 +=2를 하여 홀수만 계산토록한다.
         */
        for(i=1;i<prt;i++){//소수의 개수 만큼 반복
            cnt ++;//계산 횟수를 증가한다.
            if(n%prime[i] == 0)break;
            //n과 소수의 개수를 저장하는 배열과 반복하여 비교한 후, 나머지가 0인 경우 반복을 종료한다.
             
        }
        if(prt == i) prime[prt++] = n;
        //for문이 정상적으로 끝까지 반복한 경우 해당 숫자를 소수 배열의 요소로 추가한다.
    }
    for(int i=0;i<prt;i++)printf("%d\n",prime[i]);
    printf("나눗셈을 시행한 횟수: %d\n",cnt);
}