#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[ 문제 2 ] (20점) N (2 ≤ N ≤ 100) 개의 정수로 이루어진 수열 X를 
“위치 바꿈 정보”에 의해 변 환한 최종 결과를 출력하는 
프로그램을 작성하시오. 위치 바꿈 방식은 다음과 같다. 예를 들어, 10 개 정수의 수열 X와 위치 바꿈 정보가 다음과 같이 주어졌을 때,
*/
/*
[문제1] N(3≤N≤100)개의정수로이루어진수열X를
“뒤집기정보”에의해변환한최종 결과를 출력하는 프로그램을 작성하시오. 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int swap(int *num, int *snum, int swb,int idx){
    if(swb > 0){
        int tmp = num[snum[idx]]; idx++;
        swb --;
        printf("num[%d] = %d | snum[%d]\n",snum[swb],num[snum[swb]],swb);
        int cnt =  swap(num,snum,swb,idx);
        printf("num[%d] <- %d \n \n",snum[swb],cnt);
        num[snum[swb]]  = cnt;
        return tmp;
    }
    else return num[snum[swb]];

}


int main(){
    int n,swb,tmp,cnt=1; 
    scanf("%d",&n);
    signed int *num = (int *)malloc(sizeof(int)*n+1);
    signed int *snum = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    scanf("%d",&swb);

    for(int i=0;i<swb;i++){scanf("%d",&snum[i]);}
    num[snum[0]] = swap(num,snum,swb,cnt);//idx ~ swb까지하고 idx를 증가한다.

    // for(int i=0;i<swb-1;i++){
    //     printf("%d->%d\n",num[snum[i]],num[snum[i+1]] );
    //     tmp = num[snum[i+1]];
    //     num[snum[i+1]] = num[snum[i]];
    //     num[snum[i]] = tmp;

    // }
    // for(int i=swb-1;i>0;i--){
    //     if(i==swb-1)tmp = num[snum[i]];
    //     num[snum[i]] = num[snum[i-1]];
    // }num[snum[0]]
    for(int i=0;i<n;i++) printf(" %d",num[i]);

    

    
} 

/*
10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3

6
0 20 40 30 10 50 
4
1 2 4 1
*/