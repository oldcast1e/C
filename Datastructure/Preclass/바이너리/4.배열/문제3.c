#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*
[ 문제 3 ] N x N (1≤N≤100) 크기의 행렬에 1 ~ N2 의 수를 
아래 그림과 같이 차례로 위에서 부터 → 방향과 ← 방향을 번갈아 가면서 채운 결과를 출력하시오.

문제 해결 포인트: 배열을 다중배열이 아닌 1차 배열로 생각할 것.
3x3인 경우 0 ~ 2 / 3 ~ 5 / 6 ~ 9
*/
int main(){
    
    int num[101],tmp,N;scanf("%d",&N);
    int right=1,left=0,stt=0,end=N-1;
    for(int i=0;i<(N*N);i++)num[i] = i+1;
   
    for(int k=0;k<N;k++){
        if(right == 1 && left ==0){
            for(int i=stt;i<=end;i++) printf(" %d",num[i]);
            //0부터 4까지
            printf("\n");
            /**
            1. stt의 현재값:0
               stt의 변경값:9 => end +N;(end변경 전 값 사용)

               end의 현재값:4
               end의 변경값: 5
             */
            stt = end+N; //5 + 5 - 1 == 9
            end ++;
            right = 0;left = 1;
        }
        else if(left == 1 && right == 0){
            for(int i=stt;i>=end;i--) printf(" %d",num[i]);
            printf("\n");
            end  = stt+N;
            stt ++;
            /**
            2. stt의 현재값:9
               stt의 변경값: 10

               end의 현재값:5
               end의 변경값: 14 => (stt변경전 값) + N
             */

            right = 1;left = 0;
        }

    }

    return 0;
   


}