#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int candle(int n, int k){
    int *num = (int*)malloc(sizeof(int)*n);
    for(int i=1;i<=n;i++)num[i] = i; //1~10

    int remaining = n, index =1, cnt;

    while(remaining > 1){
        if(num[index]){
            printf("삭제되는 인덱스[%d]의 값: %d\n",index,num[index]);
            num[index] = 0; remaining --;
            cnt  = k;
            // index = (index+)%n+1; // 이렇게 계산하면 안됨

        }
        while(num[index] <= 0){
            printf(">>값이 0인 인덱스 : %d\n",index);
            index ++;if(index > n) index = 1;
        }
        printf("%d개 넘어간 인덱스 [%d]의 값: %d\n",k,index,num[index]);
        // if(num[index] == 0) while(num[index] != 0)index = (index+1)%10;
        // index = (index + k)%10+1;
        // printf("%d개 넘어간 인덱스: [%d]\n",k,index);

    }
    /*
    n: 양초의 개수
    k: 건너 뛸 양초의 수
    */
   return remaining;
//    printf("%d",remaining);
}

int main(){
    int n = 10;
    int k = 3;
    int remaining = candle(n,k);
    printf("%d",remaining);
}