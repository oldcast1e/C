#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>
/**[문제1] N(3≤N≤100)개의 정수로 이루어진 수열X를
 * “뒤집기정보”에 의해 변환한 최종 결과를 출력하는 프로그램을 작성하시오.
 * 
 * 10 ↦ 수열의 길이 N
 * 3 81 9 12 0 –9 36 33 91 10 ↦ 수열 X 
 * 3 ↦ 뒤집기 정보의 개수
 * 3 7 4 5 0 4 ↦ 뒤집기 구간 정보 =>>>>>>>>>(3,7) , (4,5) , (0,4)
 * 
 * 1) 뒤집기 정보 (3, 7)에 의해, 수열 X의 3번째 수부터 7번째 수까지의 순서가 반대로 바뀐다.
 * 2) 뒤집기 정보 (4, 5)에 의해, 위 수열의 4번째 수부터 5번째 수까지의 순서가 반대로 바뀐다.
 * 3) 마지막으로 (0, 4)에 의해 순서가 뒤집히고, 최종적으로 만들어지는 수열은 다음과 같다.
 */
void swap(int *X,int stt,int end){
    for(int i=stt;i<((stt+end)/2);i++){
        //4; 4
        int tmp;
        tmp  = X[i];
        X[i] = X[end-i];
        X[end-i]= tmp;
    }
    /**
    3~7: 3부터 (10/2)==5전까지

    4부터 (9/2)==4까지

    3~8: 3부터 (11/2)==5전까지
     */
}

int main(){
    int N,X[100],rvs_cnt;
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&X[i]);
    scanf("%d",&rvs_cnt);

    int *rvs_arr = (int*)malloc(sizeof(int)*(rvs_cnt*2));

    for(int j=0;j<(rvs_cnt*2);j+=2)scanf("%d %d",&rvs_arr[j],&rvs_arr[j+1]);
    // for(int i=0;i<rvs_cnt*2;i+=2)printf(">%d %d\n",rvs_arr[i],rvs_arr[i+1]);
    for(int i=0;i<rvs_cnt*2;i+=2) swap(X,rvs_arr[i],rvs_arr[i+1]);

    for(int i=0;i<N;i++)printf(" %d",X[i]);

    /**
10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4
     */


}
