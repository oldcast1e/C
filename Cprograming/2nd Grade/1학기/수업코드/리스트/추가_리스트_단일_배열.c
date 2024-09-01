#include <stdio.h>

typedef int element;

typedef struct ArrayListType{
	element list[100]; 
	int length; // 리스트 길이를 확인하기 위한 변수
}ArrayListType;

void init(ArrayListType* DList){
    DList->length = 0;
}
// L이라는 리스트의 길이를 0으로 초기화


int isEmpty(ArrayListType* DList) {
	if (DList->length == 0) return 1;
	return 0;
}

int isFull(ArrayListType* DList) {
	if (DList->length == 100) return 1;
	return 0;
}

void add(ArrayListType* DList, int position, element item) {
    if(isFull(DList)) printf("List is Full\n");
	else if ( (0 <= position) && (position <= DList->length)  ){
		for (int i = (DList->length - 1); i >= position; i--)
			DList->list[i + 1] = DList->list[i];

		DList->list[position] = item;
		DList->length++;
	}
    else printf("Positio Error\n");
}

int delete(ArrayListType* DList, int position){
	element item;
	if (position < 0 || position >= DList->length) printf("Index Error\n");
	item = DList->list[position];
	for (int i = position; i < (DList->length - 1); i++)
		DList->list[i] = DList->list[i + 1];
	DList->length--;
	return item;
}