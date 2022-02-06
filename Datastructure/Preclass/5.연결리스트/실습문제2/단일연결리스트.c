#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*연결 리스트를 구현할 구조체*/
typedef struct ListNode {
	int coef;// 항의 계수
    int exp; // 항의 차수
    struct ListNode *next;//다음 노드의 위치

    /*
    하나의 연결리스트의 각 노드는 차수의 내림차순으로 유지
    계수가 0인 항의 노드는 유지하지 않는다.

    노드의 정렬은 계수 -> 차수 수으로 정렬된다.
    */
}ListNode;

int main(void){
    int count,n,m,cnt=0,rep=0,max=-1;
    int numarr[1000][2]={0,0};

    for(int i=0;i<1000;i++)numarr[i][1] = i;
    //count: 첫 번째 다항식의 항의 계수 -> 입력받을 횟수는 count*2
    //항의 개수만큼 리스트가 필요. 단 헤더노드는 선언 후 입력받을 것.

    ListNode* firhead = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성(1)
    ListNode* sechead = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성(2)

    ListNode**arr[2] = {&firhead,&firhead};//구조체 이중 포인터 선언

    while(rep<2){
        scanf("%d",&count);
        for(int i=0;i<count;i++){//항의 계수만큼 반복하되, 한번의 입력과정에서 계수와 차수를 입력받음.
            scanf("%d %d",&n,&m);//차수와 계수를 입력받는다.

            ListNode* curr = *arr[rep]; //순회용 노드 생성
            for(cnt=0;cnt<i;cnt++)curr= curr->next;

            ListNode *new=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

            new->coef = n;//계수
            new->exp = m;//차수
            curr ->next = new;
        }
        
        ListNode* print = *arr[rep]; //순회용 노드 생성
        print = print->next;
        while(print != NULL){
            if(print->exp > max) max = print->exp;

            numarr[print->exp][0] += print->coef;//계수
            print = print->next;
        }free(print);
        rep ++;
        
    }
    // printf("max = %d",max);
    // for(int i=max;i>=0;i--)printf(" %d %d\n",numarr[i][0],numarr[i][1]);
    for(int i=max;i>=0;i--) if(numarr[i][0] != 0) printf(" %d %d",numarr[i][0],numarr[i][1]);

    
    //첫 번째 다항식의 차수
    //두 번째 다항식의 차수
    /**
    차수가 높은 순서대로 덧셈 진행

    각각의 연결리스트를 순회하고(max를 찾기위한 조건문을 수행한다.)
    해당 (차수==인덱스)에 계수를 저장(더)한다.

    이후 찾은 max부터 0까지 인덱스값을 읽는다.
    */

    
    /**
    반복문안에서 리스트를 동적할당하고, 이전 노드와 연결(이전 노드의 *next에 연결)
    */
    
    
}
/**
3
5 3 3 2 3 1
3
2 6 2 3 1 0
 */