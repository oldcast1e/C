/*
[ 문제 2 ] (개방주소법 해시테이블 – 선형조사법) 크기 M인 해시테이블에 n개의 키 값을
입력받아 저장하고, 개방주소법 중 선형조사법을 이용하여 충돌을 처리하는
해시테이블 프로그램을 작성하시오.
◦ 구현 조건
- 해시테이블은 크기가 M인 배열로 동적 할당한다.
- n은 M보다 작은 자연수로 최대 삽입 개수다.
- 입력 키는 중복이 없는 6자리 또는 8자리의 임의의 자연수(학번)다.
- 키 x에 대한 해시함수 h(x) = x % M 을 사용한다.
- 저장된 키 값이 없는 빈 버켓은 0으로 처리한다.
◦ 입력
- 해시테이블의 크기 M과 입력 데이터의 크기 n을 입력받는다.
- 삽입(i), 탐색(s) 명령어를 순서에 상관없이 반복하여 입력받는다.
i <x> : 키 x를 해시테이블에 삽입
s <x> : 키 x가 해시테이블에 존재하는지 탐색
e : 프로그램 종료
◦ 출력
- 키를 삽입하였을 때, 저장된 주소(배열 인덱스)를 인쇄한다.
- 삽입할 때 충돌이 일어나면 선형조사법에 의해 다음 셀로 이동하여 충돌 검사를 계속한다.
충돌 횟수만큼 C를 인쇄한 후, 삽입에 성공한 주소를 인쇄한다.
- 탐색한 키가 테이블에 존재할 경우, 키가 저장된 주소와 값을 인쇄한다(없을 경우 –1을
인쇄한다).

*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int *hash, m;
int h(int k) {
	return k % m;
}

int buck(int v,int i) {
	return (v + i) % m;
}

int insert(int k) {
	int v = h(k), b, i = 0;
	
	while (i < m) {
		b = buck(v, i);
		if (hash[b] == 0) {
			hash[b] = k;
			for (int j = 0; j < i; j++) printf("C");
			printf("%d\n", b); return;
		}
		else i++;
	}
	///printf("-1\n");
}

int search(int k) {
	int v = h(k), b, i = 0;

	while (i < m) {
		b = buck(v, i);
		if (hash[b] == 0) {
			printf("-1\n"); return;
		}
		else if (hash[b] == k) {
			printf("%d %d\n",b,hash[b]); return;
		}
		else i++;
	}
}

int main() {
	int n,k;
	scanf("%d %d", &m, &n);
	hash = (int*)malloc(sizeof(int)*m);
	for (int i = 0; i < m; i++) hash[i] = 0;;
	char or ;
	while (1)
	{
		scanf("%c", &or );
		if (or=='i') {
			scanf("%d", &k); getchar();
			insert(k);
		}else if (or=='s') {
			scanf("%d", &k); getchar();
			search(k);
		}else if (or=='e') {
			break;
		}
	}
}