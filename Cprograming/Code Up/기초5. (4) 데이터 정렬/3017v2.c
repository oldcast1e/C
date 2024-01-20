#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
/*연결 리스트를 구현할 구조체*/
typedef struct ListNode{
    int math,info,ogr;
    struct ListNode* next;//자가 참조 구조체
    /*다음 노드의 주소를 저장할 자기참조 구조체포인터*/
}ListNode;

ListNode* add(ListNode *head, int rank, int m_score, int i_score){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* check = head->next; //순회용 노드 생성
    while(check != NULL){
	    cnt ++;
	    check = check->next;    
    }free(check);

    // printf("cnt = %d\n",cnt);
    if(cnt > rank) {printf("invalid position");return 0;}
    else{
        ListNode* curr = head; //순회용 노드 생성
        for(int i=0;i<rank;i++)curr= curr->next;
        //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

        p->math = m_score;
        p->info = i_score;

        p->ogr = rank+1;

        p->next = curr->next;
        curr->next = p;

        // p->pre = curr;
        // (p->next)->pre = p;
        // printf("추가된 노드의 데이터는 %d입니다.\n",p->math);
        return head; //다음 노드의 위치를 반환함.
    }

}

//quick 정렬 (퀵 정렬)
void quickSort(int arr[], int L, int R){
    int left = L, right = R,tmp;
    int Piv = arr[(L+R)/2];
    do{
        while(arr[left] < Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(arr[right] > Piv) right--;
        //right Piv보다 작은 값을 만나거나 피벗(Piv)을 만날때 까지
        if( left <= right){
            tmp = arr[left];
            arr[left]= arr[right];
            arr[right] = tmp;

            left++; right --;
        }
    } while(left <= right);

    if(L < right) quickSort(arr,L,right);
    if(R > left) quickSort(arr,left,R);
}
void print(ListNode *head){
    ListNode* prt = head->next; //순회용 노드 생성
    while(prt != NULL){
	    printf("%d %d %d\n", prt->ogr,prt->math,prt->info);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}
int main(){
    int N,a,b;
    // int num[1000][2];
    scanf("%d",&N);
    // for(int i=0;i<(int)strlen(arr);i++)
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* curr = head->next; //순회용 노드 생성

    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        add(head,i,a,b);
    }

    print(head);
	
    
    // for(int i=0;i<N;i++){scanf("%d %d",&num[i][0],&num[i][1]);}
    // quickSort(num,0,N-1);
    
    // for(int i=0;i<N;i++)printf("%d %d %d\n",i+1,num[i][0],num[i][1]);

    
} 
/*
첫째 줄에 학생수 n(번호:1~n)가 입력된다. (1 <= n <= 1,000)

5
100 90
90 100
80 80
80 90
60 50
*/