#include <stdio.h>

int n;
// # 이 부분에 들어갈 코드만 작성하여 제출하세요
char grade(int n){
    if(n>=90) return 'A';
    else if(n>=80) return 'B';
    else if(n>=70) return 'C';
    else if(n>=60) return 'D';
    else return 'F';
}
/*
90 점 이상 ~ 100점 이하 : A
80 점 이상 ~ 90점 미만 : B
70 점 이상 ~ 80점 미만 : C
60 점 이상 ~ 70점 미만 : D
60 점 미만 : F 
*/
int main()
{
  scanf("%d", &n);
  printf("%c", grade(n));
  return 0;
}