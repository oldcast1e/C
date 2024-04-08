#include <stdio.h>

#define Max_ele 100
#define Sentinel 0 // 종료 입력값
#define True 1
#define False 0

int GetIntArr();
int GetInt();

void PrintIntArr();
void RevPintIntArr();
void Swap();

int GetInt() {
  int ipt;
  scanf("%d", &ipt);
  return ipt;
}

int GetIntArr(int arr[], int max, int end) {
  //인자: 수정할 배열/ 배열의 최대값 / 입력 종료값
  // 배열을 입력받는 함수
  int cnt = 0, num, val;
  while (True) {

    printf("=> ");
    val = GetInt();
    if (val == end)
      break;

    arr[cnt] = val;
    cnt++;
  }

  return cnt;
}

void PrintIntArr(int arr[], int max) {
  for (int i = 0; i < max; i++)
    printf("%d\n", arr[i]);
}

void RevPintIntArr(int arr[], int num) {
  for (int i = 0; i < num / 2; i++)
    Swap(arr, i, num - i - 1);
  // (i,num-i-1) 인 이유는 반복문의 반복은 배열의 크기의 절반이고, 짝수인 경우는
  // 중간값을 바꿀 필요가 없음. 따라서 배열의 크기의 반만 반복하되 처음과 끝을
  // 순서대로 변환하면 반전시킬 수 있다.
}

void Swap(int arr[], int n, int m) {
  int cnt = arr[n];
  arr[n] = arr[m];
  arr[m] = cnt;
}

int main() {

  int arr[Max_ele], n;
  printf("임의의 정수값을 입력하세요.\n");
  printf("0을 입력하면 입력을 종료합니다.\n");
  n = GetIntArr(arr, Max_ele, Sentinel);
  RevPintIntArr(arr, n);
  PrintIntArr(arr, n);
}