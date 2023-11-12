#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,val=1,cnt_a,cnt_b=0,rep=0;
    int num[100];
    int dnum[100][100];
    
    scanf("%d %d",&a,&b);

    while(val<a*b){
        /*
        cnt_a는 반복할 수록 작아지고
        cnt_b는 반복할 수록 커진다.
        */
        cnt_a = rep;
        cnt_b = rep;
        if(cnt_a >= a) cnt_a = a;
        for(int i=0;i<=cnt_b;i++){
            dnum[cnt_a][i] = val;
            printf("dnum[%d][%d] = %d\n",cnt_a,i,val);
            cnt_a --;
            val ++;
        }
        rep ++;
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)printf("%d ",dnum[i][j]);
        printf("\n");
    }

    
} 
/*

*/