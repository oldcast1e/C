#include <stdio.h>

int main() {
  //유식한 검색 프로그램
  int num = 0, ipt, index, rst;
  int data[100];

  int min = 0, max = 100;

  while (num < 100) {data[num] = num + 1;num++;}

  printf("검색할 값을 입력하세요: ");
  scanf("%d", &ipt);

  /*사용자가 입력한 값과 배열의 중간값을 비교하여 배열을 이등분한다.
  이때 베열의 중간값보다 작으면 배열의 앞부분과 비교, 크다면 배열의 뒷부분과
  비교한다.*/

  index = (max + min) / 2;
  while (max > min) {
    if (data[index] == ipt) {
      rst = index;
      break;
    } 
    else if (data[index] > ipt) { max = (max + min) / 2 - 1;}//배열의 중간값보다 작다면 다시 줄인 배열의 중간값과 비교
    else {min = (max + min) / 2 + 1;} //배열의 중간값보다 크다면
    index = (max + min) / 2;
  }
  printf("찾으시는 값은 data 배열의 %d 번째에 있습니다.", rst);
}