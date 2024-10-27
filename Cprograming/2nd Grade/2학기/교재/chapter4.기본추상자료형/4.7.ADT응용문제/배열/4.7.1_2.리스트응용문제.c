#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int candle(int n, int k){
    int cnt = 3; //cnt가 0이되어야 해당 인덱스의 값을 0으로 바꿈
    int remaining = n;//1이 남아있는 개수. 1이되면 함수 종료 및 반환
    
    int *num = (int*)malloc(sizeof(int)*n+1); //n개의 배열 0~n-1 : 0~9
    for(int i=0;i<n;i++)num[i] = 1; //0~9까지 각 인덱스에 1을 저장 -> 양초를 뽑았을때 0으로 바꿈

    int now = 0; // 0 <= now <= n-1
    while(remaining > 1){

        // if(num[now] == 0) {
        //     printf(">>num[now] == 0인 now = %d\n",now);
        //     now = (now+1)%n;
        // }
        while(num[now] == 0){now = (now+1)%n;}

        printf("index[%d] 제거\n",now);
        num[now] = 0; remaining --;
        // now = (now+1)%n;
        // printf("now = %d\n",now);
        for(int i=0;i<k;i++){
            if(num[now] == 0) {
                printf(">>num[now] == 0인 now = %d\n",now);
                i --;
                now = (now+1)%n;
            }
            else if(num[now] == 1) {
                printf(">>num[now] == 1인 now = %d\n",now);
                now = (now+1)%n;
            }
            // if(num[now] == 1) {
            //     // printf("index[%d] 제거\n",num[now]);
            //     num[now] = 0;
            //     remaining --;
            //     now = (now+1)%n;
            // }
        }

    }
    // if(remaining == 1) 
    return now;
}

int main(){
    int n = 10;
    int k = 3;
    int remaining = candle(n,k);
    printf("%d",remaining);
}

/*
if(num[now] == 0){
            //현재 배열이 요소가 0 인 경우 == 초가 뽑혀있는 경우
            // printf("index[%d] 제거\n",num[now]);
            // printf("[%d] -> ",now);
            // now = (now+1)%n;
            // printf("[%d]\n",now);
            continue;
        }
        if(num[now] == 1){
            printf("index[%d] 제거\n",now);
            num[now] = 0;
            remaining --;
            // now = (now+k+1)%n;
            for(int i = 0; i<k; i++){
                if(num[now] )
            }
            // cnt --;
        }

*/