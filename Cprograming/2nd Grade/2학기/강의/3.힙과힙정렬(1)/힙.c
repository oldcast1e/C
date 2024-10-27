#include <stdio.h>
#include <stdlib.h>

int HipArr[100];
int n = 0;

void upheap(int i) {
    /*
     새로운 요소가 추가될 때 그 요소가 
     힙 규칙(부모가 자식보다 크다는 "최대 힙" 성질)을 
     위반하지 않도록 위로 거슬러 올라가며 
     부모 노드와 값을 비교하고 필요하면 교환하는 방식으로 
     힙 구조를 유지하는 함수
    */
	if (i == 1 || HipArr[i] < HipArr[i / 2]) return;
    /*
    1. 현재 노드가 루트 노드인지 확인
    2. 현재 노드의 값이 부모 노드의 값보다 작은지 확인
    (HipArr[i]는 현재 노드의 값이고, HipArr[i / 2]는 그 노드의 부모 노드의 값)
    */
	int tmp = HipArr[i]; //현재 노드 데이터
	HipArr[i] = HipArr[i / 2]; // 현재 노드에 부모 노드 데이터를 저장
	HipArr[i / 2] = tmp; // 부모 노드에 현재 노드 데이터(tmp) 저장
	upheap(i / 2);  // 재귀적 수행 -> 부모 노드를 인자로 사용
}
void downheap(int i) {
    /*
    완전 이진 트리란 이진 트리에 노드를 삽입할 때 왼쪽부터 차례대로 삽입하는 트리
    최대힙의 경우에는 각 노드의 값이 자식 노드보다 크거나 같다.

    최대 힙의 특성을 유지하기 위해, 
    힙에서 루트 노드에 위치한 값이 자식 노드보다 작을 때 
    부모-자식 간의 위치를 교환하여 힙의 규칙을 유지하는 함수.
    
    주로 힙에서 값을 삭제할 때, 
    루트에 있던 값을 다른 값으로 대체한 후 사용됩니다.

    >> i는 부모 노드의 인덱스임
    */
	int big = i * 2; //현재 노드의 왼쪽 자식 노드의 인덱스를 구하기 위해 사용
    /*
    왼쪽 자식의 인덱스: 2 * i (즉, i * 2)
    오른쪽 자식의 인덱스: 2 * i + 1 (즉, i * 2 + 1)    
        
              1
            /   \
           2     3
          / \    / \
         4   5  6   7

    */
	if (big > n) return;//범위를 넘어간 경우

	if ((big + 1 <= n) && HipArr[big] < HipArr[big + 1]) big++;
    // 오른쪽 자식 노드가 존재하고, 오른쪽 자식이 더 크면 오른쪽 자식 인덱스로 변경

    /*
    오른쪽 자식 인덱스로 변경하는 이유는, 
    최대 힙(max heap)에서는 부모 노드가 자식 노드보다 크거나 같아야 하므로, 
    자식 노드 중 더 큰 값을 가진 자식으로 내려가야 
    힙의 성질을 유지할 수 있기 때문.
    */

	if (HipArr[big] > HipArr[i]) {
		int tmp = HipArr[i];
		HipArr[i] = HipArr[big];
		HipArr[big] = tmp;

        //현재 노드(부모,i)와 자식 노드(좌/우 중 큰 값)과 swap
		downheap(big);
	}
}
void removemax() {
	printf("%d\n", HipArr[1]);
	HipArr[1] = HipArr[n];
	n--;
	downheap(1);
}
void insertItem(int data) {
	printf("0\n");
	n++;//범위 증가
	HipArr[n] = data;
	upheap(n);
}

void select() {
	for (int i = n-1; i >= 1; i--)
	{
		int max_idx=i;
		for (int j = 0; j < i; j++) {
			if (HipArr[j] > HipArr[max_idx]) max_idx = j;
		}
		int tmp = HipArr[i];
		HipArr[i] = HipArr[max_idx];
		HipArr[max_idx] = tmp;
	}
	//printheap();
}

void rBuildHeap(int i) {
    /*
    주어진 배열을 사용하여 최대 힙(max heap)을 구축하는 함수.
    이 과정에서는 배열의 모든 요소를 힙 구조로 변환하여 
    부모 노드가 자식 노드보다 크거나 같도록 합니다. 
    
    일반적으로 하향식(downheap) 조정 방법을 사용하여 
    배열의 중간 인덱스부터 시작해 각 노드에 대해 
    힙 성질을 유지하는 방식으로 진행됩니다.
    */
	if (i > n) return;//현재 노드 인덱스 i가 배열의 크기 n을 초과하면 함수 실행을 종료
	rBuildHeap(i * 2);//쪽 자식 노드에 대해 재귀적으로 rBuildHeap을 호출
	rBuildHeap(i * 2+1);// 오른쪽 자식 노드에 대해 재귀적으로 호출
	downheap(i);

    /*현재 노드에 대해 하향식 조정을 수행합니다. 
    downheap 함수는 현재 노드와 그 자식 노드의 값을 비교하여 
    필요한 경우 교환하고, 힙 성질을 유지하기 위해 계속 하향식 조정을 수행.*/
}

void printheap(){
	for (int i = 1; i <=n; i++) {
		printf("%d ", HipArr[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &HipArr[i]);
	rBuildHeap(1);
	printheap();
}
