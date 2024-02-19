#include <stdio.h>
void f()
{
  printf("hello\n");
  return; //호출했던 위치로 복귀(함수 실행이 종료됨)
}
int main()
{
    f();
    return 0;
}