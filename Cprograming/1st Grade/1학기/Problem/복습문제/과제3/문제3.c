#include  <stdio.h>
int main(){

    int N,spn,sn,cnt,k=0;
    //spn: 스페이스 입력 횟수
    //sn: 별 출력 횟수
    scanf("%d",&N);
    spn = N;
    for(int i=1;i<=N-1;i++){ //3이면 1~2(줄) 출력
        cnt = spn;
        while(cnt-1>0){
            printf(" ");
            cnt--;
        }

        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        spn --;
        printf("\n");
    }
    spn = 0;
    cnt = 0;
    for(int i=N;i>=1;i--){ //5이면 5~9(줄) 출력
        if(k!=0){
            printf("\n");
        }
        while(cnt>0){
            printf(" ");
            cnt--;
        }

        for(int j=2*i-1;j>=1;j--){
            printf("*");
        }
        spn ++;
        cnt = spn;
        
        k++;

    }


}