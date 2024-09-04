#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
 문제 1 ] 위에서 설명한 이중연결리스트를 이용하여 영문자 리스트 ADT를 구현하시오.
◦ 다음 네 가지 연산을 지원해야 함 (순위는 1부터 시작한다고 가정)
- add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
- delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다. (주교재의 remove와 동일)
- get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
- print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.
※ 순위 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position"을 출력하고, 해당
연산을 무시한다.
*/
typedef char element;

typedef struct ListNode {
	int data;
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	struct ListNode* Head;
    int size;
}ListType;

void init()


void add(ListNode* Head, int rank, int e){

}

int main(){

}

