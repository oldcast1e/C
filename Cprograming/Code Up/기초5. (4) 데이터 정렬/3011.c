#include <stdio.h>
int a[10001];
int n, i, j, temp,key=1;

int main() {

    int cnt = 0,rst=0;    
    scanf("%d", &n);
    for (i=1; i<=n; i++)scanf("%d", &a[i]);

    for(i=1; i<n; i++){
        key =1;
        for(j=1; j<=n-i; j++){
            cnt ++;
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        // printf("[%d] ",i);for (int k = 1; k <= n; k++)printf("%d ", a[k]);

        for(j=n-i ;j>=2; j--){
            if(a[j] < a[j-1]) {key = 0;break;}
        }
        /*후순으로 비교함: 비교 도중 앞요소가 뒤요소(판별값)보다 큰 경우(40 30) ==>> 더 반복을 돌려 정렬해야하므로, 해당 비교문 종료
        다시말해 비교문이 종료 되고 key가 0이면 정렬이 다 되지 않은 상태 

        만약 key값이 1이라면 정렬이 다 된 것임.
        */
       if(key == 1){rst = i;break;}
        // rst ++;
        // if(key==0)break;

    }
    // printf(">>%d\n",cnt);
    rst = rst == 0?1:rst;
    printf("%d",rst);
    // for (i = 1; i <= n; i++)printf("%d ", a[i]);
}

/*
2
-1 -3

1
*/