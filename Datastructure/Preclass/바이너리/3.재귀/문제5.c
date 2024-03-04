/*[ 문제 5 ] 원반의 개수 N을 입력받아, 하노이 탑 문제의 수행과정을 예시와 같이 출력하는 프로 그램을 작성하시오.*/

/**
◦ 하노이 탑(towers of Hanoi) 문제
- 세 개의 말뚝: A, B, C
- 초기 상황: 직경이 다른 N>0 개의 원반이 A에 쌓여 있음 - 목표: 모든 원반을 A로부터 C로 옮김
◦ 조건
- 한 번에 말뚝의 가장 위에 있는 한 개의 원반만 이동 가능 - 직경이 큰 원반은 작은 원반 위에 놓일 수 없음
- 남은 말뚝을 보조 말뚝으로 사용 가능
 */
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>


void hanoi_tower(int n, char from, char tmp, char to) {
    //  A B C
	if (n == 1) {
		printf("%c %c\n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("%c %c\n", from, to);
		// hanoi_tower(n - 1, tmp, from, to);
	}
}
int main() {
    int n;scanf("%d",&n);
    char from = 'A',tmp = 'B',to = 'C';
    hanoi_tower(n,from,tmp,to);
}
