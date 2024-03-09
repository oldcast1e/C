#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arr[50];
void swap(int *a,int *b){
    int tmp;
    tmp  = arr[*a]; arr[*a] = arr[*b]; arr[*b] = tmp;
}
// swap( ) 함수
// 출력 예시 1 □3 2 4 1 0 6
// - 인자: 두 개의 int 포인터 (배열 원소 값이나 인덱스가 인자가 아님에 유의) - 인자가 가리키는 두 변수의 값 교환
// - 반환 값: 없음
int main(){
    int n,a,b; scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    for(int i=0;i<n;i++)printf(" %d",arr[i]);
    // for(int i=0;i<n;i++)

} 
/*[ 문제 3 ] N개의 정수를 입력 받아 배열에 저장한 후 (N ≤ 50),
 다시 배열에서 값을 교환하고 싶 은 인덱스 a 와 b를 입력 받는다. 
 인덱스 a 와 b 위치의 요소 값들이 교환된 배열을 출력하는 프 로그램을 작성하시오.
6
3 2 0 1 4 6
2 4
 ↦ab
 
 */