#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int num[100001],N,cnt=0,min;
    scanf("%d",&N);
    int *rst = (int*)malloc((N*(N-1)/2)*sizeof(int));

    int idx[2],val;

    for(int i=0;i<N;i++)scanf("%d",&num[i]);

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            rst[cnt] = num[i] + num[j];

            if(cnt==0)min = rst[0];

            if(min>abs(rst[cnt])){
                val = rst[cnt];
                min= abs(rst[cnt]);
                idx[0] = num[i];
                idx[1] = num[j];
            }
            cnt ++;
        }
    }
    // for(int i=0;i<10;i++)rst[i] = i +1;
    // for(int i=0;i<(N*(N-1)/2);i++)printf("%d ",rst[i]);
    // printf("\nval = %d | %d + %d",val,idx[0],idx[1]);
    printf("\n");
    printf("%d %d",idx[0],idx[1]);

    
} 
/*
-1  2
*/