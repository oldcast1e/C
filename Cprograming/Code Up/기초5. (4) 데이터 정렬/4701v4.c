#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int num[100001],N,cnt=0,min;
    scanf("%d",&N);

    int idx[2],val;

    for(int i=0;i<N;i++)scanf("%d",&num[i]);

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            val = num[i] + num[j];

            if(cnt==0)min = abs(val);

            if(min>=abs(val)){
                min = abs(val);
                idx[0] = num[i];
                idx[1] = num[j];
            }
            cnt ++;
        }
    }
    // for(int i=0;i<10;i++)rst[i] = i +1;
    // for(int i=0;i<(N*(N-1)/2);i++)printf("%d ",rst[i]);
    // printf("\nval = %d | %d + %d",val,idx[0],idx[1]);
    if(idx[0] > idx[1]){
        int tmp;
        tmp = idx[0]; idx[0] = idx[1];
        idx[1] = tmp;
    }
    printf("%d %d",idx[0],idx[1]);

    
} 
/*
-1  2
*/