#include <stdio.h>
#include <stdlib.h>

typedef char element;
#define MAX_SIZE 100 // 배열의 최대 크기 정의

// 이진 트리 구조체 정의
typedef struct {
    int size; // 현재 트리의 크기
    int elements[MAX_SIZE]; // 트리를 저장하는 배열
} BinaryTree;

typedef struct {
    element *que;

    int front;
    int rear;
    int size; // 현재 트리의 크기
    int max;
} QueType;

void init(BinaryTree *T){
    T->size = 0;
}

void initQue(QueType *Q){
    Q->que  = (element *)malloc(sizeof(element)*MAX_SIZE);
    Q->front  = Q->rear  =  -1;
    Q->max = MAX_SIZE;
    Q->size = 0;
}

void enque(QueType *Q, element e){
    if(Q->size >= Q->max) {printf("Queue is Full.");exit(1);}
    else{
        Q->que[ ++ Q->rear ] = e;
        Q->size ++;
    }
}

element deque(QueType *Q){
    if(Q->size <= 0 ) {printf("Queue is Empty");exit(1);}
    element e = Q->que[Q->front + 1];
    Q->front ++;
    return e;
}
/*
부모 노드: 노드 i의 부모는 ⌊i/2⌋ 인덱스에 위치합니다.
왼쪽 자식 노드: 노드 i의 왼쪽 자식은 2i 인덱스에 위치합니다.
오른쪽 자식 노드: 노드 i의 오른쪽 자식은 2i + 1 인덱스에 위치합니다.
형제 노드: 노드 i의 형제 노드는 i가 짝수면 i + 1, 홀수면 i - 1 인덱스에 위치합니다.

*/

void makeNode(BinaryTree* T, element e){
    /*
    - 새로운 노드를 삽입할 때, 배열의 다음 빈 인덱스에 삽입합니다.
    - 삽입 후, 부모 노드와의 관계를 유지하기 위해 인덱스를 계산합니다.
    */
    T->elements[++T->size] = e;
}

int isEmpty(BinaryTree *T){return(T->size == 0);}
int isRoot(BinaryTree *T, element e){return(T->elements[1] == e);}
int size(BinaryTree *T){return(T->size);}

element root(BinaryTree *T){
    //루트 노드의 인덱스는 1부터 정의
    if(isEmpty(T)) {printf("Invaild."); exit(1);}
    return(T->elements[1]);
}

element parent(BinaryTree* T, element e){
    if(isEmpty(T)) {printf("Invaild."); exit(1);}
    int index;
    for(int i=1;i<T->size;i++){if(T->elements[i] == e) {index = i; break;}}
    return(T->elements[index/2]);
}

element left(BinaryTree* T, element e){
    if(isEmpty(T)) {printf("Invaild."); exit(1);}
    int index;
    for(int i=1;i<T->size;i++){if(T->elements[i] == e) {index = i; break;}}
    return(T->elements[2*index]);
}

element right(BinaryTree* T, element e){
    if(isEmpty(T)) {printf("Invaild."); exit(1);}
    int index;
    for(int i=1;i<T->size;i++){if(T->elements[i] == e) {index = i; break;}}
    return(T->elements[2*index+1]);
}

void preorder(BinaryTree* T, int i){
    /*전위 순회 : 부모 노드 -> 왼쪽 자식 노드 -> 왼쪽 자식 노드*/
    if(i <= T->size ){
        printf("[%c]",T->elements[i]);
        preorder(T,2*i);
        preorder(T,2*i+1);
    }
}

void inorder(BinaryTree* T, int i){
    /*중위 순회 : 왼쪽 자식 노드 -> 부모 노드 -> 왼쪽 자식 노드*/
    if(i <= T->size ){
        inorder(T,2*i);
        printf("[%c]",T->elements[i]);
        inorder(T,2*i+1);
    }
}

void postorder(BinaryTree* T, int i){
    /*중위 순회 : 왼쪽 자식 노드 -> 부모 노드 -> 왼쪽 자식 노드*/
    if(i <= T->size ){
        postorder(T,2*i);
        postorder(T,2*i+1);
        printf("[%c]",T->elements[i]);
    }
}

void printQue(QueType* Q){
    for(int i =  Q->front + 1; i <= Q->rear  ; i++){
        printf("<%c>",Q->que[i]);
    }printf("\n");
}

void levelOrder(QueType *Q,BinaryTree* T){
    int index;
    element d =  deque(Q);
    printf("(%c)",d);

    for(int i = 1 ; i < T->size + 1 ; i++)if(T->elements[i] == d){index = i; break;}

    // printf("d = %c | index = %d\n",d,index);
    enque(Q,T->elements[index*2]);
    enque(Q,T->elements[index*2+1]);
    // printQue(Q);
    if(index < T->size){levelOrder(Q,T);}
}


void print(BinaryTree* T){
    for(int i = 1 ; i < T->size + 1 ; i++){
        printf("[%c]",T->elements[i]);
    }printf("\n");
}

int main(){
    BinaryTree T; init(&T);
    for(int i = 0 ; i < 10 ; i++) makeNode(&T,'A'+i);
    
    printf("Bisic Tree: ");print(&T);
    printf("Preorder Tree: ");preorder(&T,1); printf("\n");
    printf("Inorder Tree: ");inorder(&T,1); printf("\n");
    printf("Postorder Tree: ");postorder(&T,1); printf("\n");

    QueType Q; initQue(&Q);
    // if(Q.size == 0){printf("[%c]",T.elements[0]);}
    enque(&Q,T.elements[1]);
    // enque(&Q,T.elements[2]);printQue(&Q);
    printf("levelOrder Tree: ");levelOrder(&Q,&T);

}
/*
[A][B][C][D][E][F][G][H][I]

                                A
                B                               C
        D                E               F             G
    H       I       J

전위 순회 결과:[A][B][D][H][I][E][J][C][F][G]
중위 순회 결과: [H][D][I][B][J][E][A][F][C][G]
후위 순회 결과: [H][I][D][J][E][B][F][G][C][A]

*/