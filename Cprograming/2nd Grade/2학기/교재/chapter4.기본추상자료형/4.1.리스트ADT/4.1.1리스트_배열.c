#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

typedef int element;
/*
리스트 크기 및 상태 관련 함수
>> integer size(): 리스트의 크기(원소 수)를 반환
>> boolean isEmpty(): 리스트가 비어 있는지 여부를 반환
*/
int size(int *num, int n){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(num[i] == -1) break;
        cnt ++;
    }
    return cnt;
}

bool isEmpty(int* num){return(num[0]==-1?0:1);}
/*
리스트 원소 접근 및 수정 함수
>> iterator elements(): 리스트의 원소 전체를 반환
>> clement get(r): 순위 r에 저장된 원소를 반환
>> element set(r, e): 순위 r에 저장된 원소를 e로 대체
*/
void iterator(int* num, int n){
    for (int i = 0; i < n; i++){
        if(num[i] == -1) break;
        printf("%d ",num[i]);
    }
}

element get(int *num, int r){
    element rtv;
    if(num[0] == -1) return -1;

    for (int i = 0; i < r; i++) rtv = num[i];
    return rtv;
}

void set(int *num, int r, int e){
    element rtv;
    if(num[0] == -1) return ;
    num[r] = e;
}


/*
리스트 삽입 함수
>> add(r, e): 순위 r 앞에 원소 e를 삽입
>> addFirst(e): 리스트 맨 앞에 원소 e를 삽입
>> addLast(e): 리스트 맨 뒤에 원소 e를 추가
*/

/*
리스트 삭제 함수
>> clement remove(r): 순위 r에 저장된 원소를 삭제하여 반환
>> clement removeFirst(): 리스트 맨 앞에 저장된 원소를 삭제하여 반환
>> clement removeLast(): 리스트 맨 뒤에 저장된 원소를 삭제하여 반환

예외 처리 관련 함수
>> invalidRankException(): 부당한 순위에 대한 접근으로 인해 처리 불가능한 상황에서 발생
>> fullListException(): 리스트가 만원이어서 처리 불가능한 상황에서 발생
>> emptyListException(): 리스트가 비어 있어 처리 불가능한 상황에서 발생
*/

int main(){
    int n; 
    printf("배열의 크기를 입력하세요: "); scanf("%d",&n);
    int *num = (int*)malloc(sizeof(int)*n);



}