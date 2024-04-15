#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*정답*/
/*
10개의 정수를 입력으로 받아, 
가장 큰 수부터 내림차순으로 정렬하여 출력하는 프로 그램을 작성 하시오.
*/
void ABC(int *num, int k){
    int max_idx,tmp,max = num[k];
    for(int i=k;i<10;i++){
        if(max < num[i]){
            max =  num[i];
            max_idx = i; 
            // printf("max = %d\n",max);
            tmp = num[k]; 
            num[k] = num[max_idx];
            num[max_idx] = tmp;
        }
    } 
}
/*
인자: int 배열, 정수 k
- 배열의 k 번째 정수부터 마지막 정수(즉, 9번째 정수)중 
    가장 큰 정수를 찾고, 이를 k 번째 위치의 정수와 교환한다.
- 반환 값: 없음
*/


int main(){
 
    int num[11]; 
    for(int k=0;k<10;k++)scanf("%d",&num[k]);
    
    for(int k=0;k<10;k++){
        ABC(num,k);    
    }
    for(int k=0;k<10;k++)printf("%d ",num[k]);
    // printf("%d",sum(n));
} 
/*
1 3 5 7 9 2 4 6 8 10
 10 9 8 7 6 5 4 3 2 1
*/
