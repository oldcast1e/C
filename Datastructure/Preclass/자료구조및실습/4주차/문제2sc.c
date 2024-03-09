#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int swap(int *num, int *snum, int swb){
    
// }


int main(){
    int n,swb,tmp,cnt=1; 
    scanf("%d",&n);//수열의 크기
    signed int *num = (int *)malloc(sizeof(int)*n+1);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);//첫번째 수열 입력

    scanf("%d",&swb);//바꿈 정보 횟수 입력
    signed int *snum = (int *)malloc(sizeof(int)*swb);
    for(int i=0;i<swb;i++)scanf("%d",&snum[i]);//두번째 수열 입력
    
    signed int *save = (int *)malloc(sizeof(int)*(swb-1));
    for(int i=0;i<swb-1;i++){
        save[i] = num[snum[i]];
        // printf("save[%d] = %d\n",i,num[snum[i]]);
    }n
    for(int i=0;i<swb-1;i++){
        // printf("%d <- %d\n",num[snum[swb-1-i]],save[swb-2-i]);
        num[snum[swb-1-i]] = save[swb-2-i] ;
    }

    
    // for(int i=0;i<swb;i++){scanf("%d",&snum[i]);}//위치 바꿈 정보

    /*3 8 0 9 3*/
    // for(int i=0;i<swb;i++){

    // }
    // num[snum[0]] = swap(num,snum,swb,cnt);//idx ~ swb까지하고 idx를 증가한다.
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