#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct {
    int *data; // 스택의 데이터를 저장할 배열
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수

    //top : 0 부터 시작(-1 일때, 스택은 비어있음 | MAX_SIZE-1일때, 스택은 가득 차있음 )
} StackType;

void init(StackType* S){
    S->data = (int *)malloc(sizeof(int)*MAX_SIZE);
    S->top = 0;
}

int isEmpty(StackType* S) {return(S->top <= 0);}

int isFull(StackType* S) {return ( S->top == (MAX_SIZE - 1));}

void push(StackType* S, element e){
    if(isFull(S)) printf("Stack is Full.\n");
    else{S->data[S->top++] = e;}
}

element pop(StackType* S){
    if(isEmpty(S)){ printf("Stack is Empty.\n"); 
        // return -1;
        exit(1);
    }
    else{
        element e = S->data[S->top-1];
        S->top --;
        return e;
    }
}

element top(StackType* S){
    if(isEmpty(S)){ printf("Stack is Empty.\n"); exit(1);}
    return S->data[S->top-1];
}

int size(StackType* S){
    // if(isEmpty(S)){ printf("Stack is Empty.\n"); return -1;}
    return ( S->top + 1);
}

int isExist(StackType* S, element e){
    for(int i=0;i< size(S); i++){
        if(S->data[i] == e) return 1;
    }return 0;
}

void print(StackType* S){
    for(int i=0;i< size(S) -1 ; i++){
        printf(" %d",S->data[i]);
    }printf("\n");
}


// void upSort(StackType* S){
//     int n = size(S);
//     for(int i = 1; i < n; i++){
//         element key = S->data[i];
//         int left = 0;
//         int right = i - 1;

//         // 이진 탐색을 통해 key가 삽입될 위치를 찾음
//         while(left <= right){
//             int mid = (left + right) / 2;
//             if(S->data[mid] > key)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }

//         // key를 삽입하기 위해 요소를 이동
//         for(int j = i - 1; j >= left; j--){
//             S->data[j + 1] = S->data[j];
//         }
//         S->data[left] = key;
//     }
// }

void upSort(StackType *S){
    for(int i=0;i< size(S) - 1 ;i++){
        for(int j=i+1;j< size(S) - 1; j++){
            if(S->data[i] > S->data[j]){
                int tmp = S->data[i] ;
                S->data[i] = S->data[j];
                S->data[j] = tmp;
            }
        }
    }
}


int main(){
    StackType A,B;init(&A);init(&B);
    srand(time(NULL));

    element e;
    int repA = rand()%15 + 1;
    for(int i=0;i< repA; i++){
        // srand(time(NULL));
        e = rand()%99 + 1;
        if(!isExist(&A,e)) push(&A,e);
    }
    // printf("Stack A :");print(&A);
    upSort(&A);print(&A);
    // printf("Sorted Stack A :");print(&A);
    for(int i=0;i< rand()%9 + 1; i++){
        printf("[%d] is poped.\n",pop(&A));
    }
    print(&A);
    printf("Peeked Data : [%d]\n",top(&A) );

}