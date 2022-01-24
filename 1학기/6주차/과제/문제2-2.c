#include <stdio.h> 

int main()
{
	int N,M;//두개의 정수 선언
	int maxnum=0, maxcnt=0, now;//약수의 개수가 가장큰 수와 그 수의 약수 

	scanf("%d %d", &N, &M);//정수를 입력받음
	for (int i = N; i <= M; i++) {//N~M까지의 숫자
		now = 0;//now를 0으로 초기화
		for (int j = 1; j <= i; j++) {//약수 찾기
			if (i % j == 0) {
				now++;//약수의 갯수
			}
		}
		//최대약수갯수보다 현재약수갯수가 클 때 맥스값에 저장
		if (maxcnt < now) {
			maxcnt = now;//약수의 개수
			maxnum = i;//약수가 가장 큰 수
		}
	}

	printf("%d %d", maxnum, maxcnt);//출력


	return 0;

}