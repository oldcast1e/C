#include <stdio.h>

int d(int num);										//정수를 인자로 가지며, 정수를 반환하는 함수 d 선언
int numstr[10001] = { 0 };								//인덱스에 해당하는 숫자가 셀프 넘버라면 해당 요소 0, 아니면 1

int main(void) {
	int i, selfnum;
	for (i = 1; i <= 10000; i++) {
		selfnum = i;
		while (selfnum <= 10000) {						//10000보다 작거나 같은 범위에서 반복
			selfnum = d(selfnum);
		}
	}
	for (i = 1; i < 10001; i++) {					//결과 출력
		if (numstr[i] == 0)printf("%d\n", i);
	}

	return 0;
}
	
int d(int num) {									//함수 d 정의
	int numindex = num;								//받은 인자의 초기값을 numindex에 저장
	while (num) {
		numindex += (num % 10);						//초기값에 일의 자리부터 계속 더해줌
		num /= 10;
	}
	numstr[numindex] = 1;									//(만들어진 수 != 셀프 넘버) 이므로 해당 인덱스 요소에 1 저장

	return numindex;									//만들어진 수 numindex 반환
}


