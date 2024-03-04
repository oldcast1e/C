#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**

[ 문제 3 ] N개의 정수를 입력 받아 배열에 저장한 후 (N ≤ 50), 
다시 배열에서 값을 교환하고 싶 은 인덱스 a 와 b를 입력 받는다. 
인덱스 a 와 b 위치의 요소 값들이 교환된 배열을 출력하는 프로그램을 작성하시오.
◦ 인덱스 a, b의 상대적 크기는 정해져 있지 않다. 즉, a < b 혹은 a > b.
 */

void swap(int *n,int *m){
    int tmp;
    tmp = *n;*n=*m;*m = tmp;
}
int main(){
    int N,n,m,num[51];scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    scanf("%d %d",&n,&m);
    swap(num+n,num+m);
    for(int i=0;i<N;i++)printf("%d ",num[i]);
/**
6
3 2 0 1 4 6 
2 4 
 */


}