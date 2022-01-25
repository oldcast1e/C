#include<stdio.h>
int main(void)

{
  unsigned int bit = 1;  // 쉬프트 연산 때문에 unsigned 지정
  int n, print_on=0;
 
  printf("십진수 양수 입력: ");
  scanf(" %d", &n);

  bit <<= (sizeof(int)*8-1); // 최상위 비트 1 설정
 
  if(n==0)  // 0일 때는 0만 출력하고 종료ㅁ
    printf("0");
  else {
    while(bit>0) {
       if(bit&n && print_on==0)  //첫번째 1을 만나면
          print_on=1;              // 출력 가능으로 지정
       if(print_on)
          printf("%d", (bit&n)?1:0);
       bit >>= 1;          // 다음 비트 검사...
     }
  } 
  return 0;
}
/*

*/