#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int n,m,cnt=0,tmp;
    int a[100],*pa = a,b[100],*pb = b;
    
    while(1){
        scanf("%d",(pa+cnt));
        if(*(pa+cnt)==0) break;
        cnt++;
    }
    n = cnt; cnt = 0;
    while(1){
        scanf("%d",(pb+cnt));
        if(*(pb+cnt)==0) break;
        cnt++;
    }
    m = cnt;

    for(int i=n;i<n+m;i++){
        *(pa+i) = *(pb+i-n);
        // printf("<%d>\n",*(pb+i-n));
    }

    for(int i=0;i<n+m;i++){
        for(int j=i;j<n+m;j++){
            if(*(pa+i)<*(pa+j)){
                tmp = *(pa+i);
                *(pa+i) = *(pa+j);
                *(pa+j) = tmp;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",*(pa+i));
    }
    printf("\n");
    for(int i=n+m-1;i>n-1;i--){
        printf("%d ",*(pa+i));
    }



//100 20 90 30 20 100 200 40 50 10 0
//5 55 85 105 205 5 15 55 25 45 0

}

/*
205 200 105 100 100 90 85 55 55 50
출력 예시 3
5 5 10 15 20 20 25 30 40 45

*/