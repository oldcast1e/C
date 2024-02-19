#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int arr[5001],gen[5001],n,m,val=0;
    for(int i=1;i<=5000;i++){
        int tmp = i,val = 0;
        while(tmp>0){
            val += tmp%10; tmp/=10;
        }
        gen[i] = i + val;
    }

    for(int i=1;i<=5000;i++)arr[i] = i;

    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++){//1 ~ 10
        for(int j=1;j<=m;j++){//1~10
            if(i==gen[j]){arr[i] =-1;break;}
            // else if(i<gen[j]) {
            //     printf(">>%d\n",i);
            //     val += i;
            //     break;
            // }
        }
    }
    // for(int i=1;i<=100;i++)printf("%d ",gen[i]);
    for(int i=n;i<=m;i++){
        if(arr[i]!=-1){
            // printf(">>%d\n",i);
        val += i;
        }
    }
    printf("%d",val);
} 
/*
어떤 자연수 n이 있을 때, d(n)을 n의 각 자릿수 숫자들과 n 자신을 더한 숫자라고 정의하자.
시작 값(a)과 마지막 값(b)이 공백으로 분리되어 입력된다.( 1 <= a <= b <= 5,000)
*/