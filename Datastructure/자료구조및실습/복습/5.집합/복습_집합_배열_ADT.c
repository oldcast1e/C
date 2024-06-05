#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef int element;

typedef struct {
    element* arr; // 원소들을 저장할 배열
    int size;          // 현재 원소 개수
    int cap;      // 배열의 용량
} SetType;

void initSet(SetType *S){
    S->arr = (int*)malloc(sizeof(int)*MAX);
    S->size = 0; // 원소의 개수
    S->cap = MAX;
}

int size(SetType *S){
    //집합의 원소 개수를 반환합니다.
    return S->size;
}

int isEmpty(SetType *S){
    return (S->size == 0);
}

int isFull(SetType *S){
    return (S->size == S->cap);
}

element* elements(SetType *S) {return S->arr;}

int isMember(SetType *S,element e){
    for(int i=0;i<S->size;i++){
        if(S->arr[i] == e) return 1;
    }return 0;
}

int subset(SetType *S, SetType * B){
    //현재 집합이 집합 B의 부분집합인지 여부를 반환합니다.
    /*
    현재 집합이 집합 B의 부분집합이기 위해서는
    현재 집합 S에 있는 요소가 무조건 집합 B에 속해야한다.
    집합에 속하는 요소는 모두 크기 순으로 정렬되 있다고 가정한다.

    집합 S를 순회
    1. B 집합을 순회한다. 
    2. B집합의 요소를 모두 순회 할 때까지 같은 값이 없으면 return 0;
    3. B집합의 요소를 모두 순회 할 때 같은 값이 나오면 contine
    */
    int cnt = 0;
    for(int i=0; i < S->size ; i++){
        for(int j=0; j < B->size ; j++){
            if(S->arr[i] == B->arr[j])cnt ++;
        }
    } 
    return (cnt == S->size);
}

void addElem(SetType *S, element e){
    S->arr[S->size ++] = e;
}

// void removeElem(SetType *S, element e){
//     // 원소 e를 집합에서 제거합니다.
//     int *tmp = (int *)malloc(sizeof(int)*MAX);
//     int cnt = 0;
//     for(int i=0;i<S->size;i++){
//         if(S->arr[i] == e) break;
//         tmp[cnt]  = S->arr[i]; cnt ++;
//     }
//     for(int i=cnt+1;i<S->size;i++){tmp[cnt]  = S->arr[i]; cnt ++;}
//     S->arr = tmp;
//     S->size -- ;
// }

// void removeElem(SetType *S, element e){
//     // 원소 e를 집합에서 제거합니다.
//     // int *tmp = (int *)malloc(sizeof(int));//메모리 누수 발생
//     int *tmp = (int *)malloc(sizeof(int)*S->size-1);
//     int cnt = 0;
//     for(int i=0;i < S->size; i++){
//         if(S->arr[i] != e) tmp[cnt ++ ] = S->arr[i]; 
//     }
//     S->arr = tmp;
//     S->size -- ;
// }

void removeElem(SetType *S, element e){
    // 원소 e를 집합에서 제거합니다.
    int *tmp = (int *)malloc(sizeof(int) * (S->size-1));
    int cnt = 0;
    for(int i=0;i < S->size; i++){
        if(S->arr[i] != e) tmp[cnt ++ ] = S->arr[i]; 
    }
    S->arr = tmp;
    S->size -- ;
}


void print(SetType *S){
    for(int i=0;i<S->size;i++){
        printf(" %d",S->arr[i]);
    } printf("\n");
}
// 합집합
SetType  UnionSet(SetType *S, SetType * B){
    // SetType *U = (SetType*)malloc(sizeof(SetType)*MAX);
    SetType U; initSet(&U);

    while(S->size > 0 && B->size > 0){
        if(S->arr[S->size - 1] == B->arr[B->size - 1]){
            addElem(&U,S->arr[S->size - 1]);
            S->size --;
            B->size --;
        }
        else if(S->arr[S->size - 1] > B->arr[B->size - 1]){
            addElem(&U,S->arr[S->size - 1]);
            S->size --;
        }
        else if(S->arr[S->size - 1] < B->arr[B->size - 1]){
            addElem(&U,B->arr[B->size - 1]);
            B->size --;
        }
    }

    while(S->size > 0){
        addElem(&U,S->arr[S->size - 1]);
            S->size --;
    }
    while(B->size > 0){
        // printf("add : %d\n",B->arr[B->size - 1]);
        addElem(&U,B->arr[B->size - 1]);
            B->size --;
    }

    return U;
}
// //교집합
// SetType * Intersect(SetType *S, SetType * B){

// }
// //차집합
// SetType * Subtract(SetType *S, SetType * B){

// }

void randAdd(SetType *S){
    while(!isFull(S)){
    // srand(time(NULL));
        element e = rand()%99;
        // while(S->arr[S->size-1] > e) e = rand()%99;
        // if(!isMember(S,e) && (S->size == 0 || S->arr[S->size-1] > e)) addElem(S,e);
        // if(!isMember(S,e) && S->arr[S->size-1] > e) addElem(S,e);
        int val = e;
        if(S->size!=0){
            val = S->arr[S->size-1];
            // printf("e : %d | Pre Value : %d | %d\n",e,val,e > val);
            
        }
        // if((e > val)) addElem(S,e);
         if(!isMember(S,e))addElem(S,e);
    }
}

//  void randAdd(SetType *S){
//     srand(time(NULL));

//     while(!isFull(S)){
//         element e = rand()%9;
//         if (S->size == 0 || e > S->arr[S->size - 1]) {
//             if(!isMember(S, e)) {
//                 addElem(S, e);
//             }
//         }
//     }
// }

void upSort(SetType *S){
    for(int i=0;i< S->size; i++){
        for(int j=i+1;j< S->size; j++){
            if(S->arr[i] > S->arr[j]){
                int tmp = S->arr[i];
                S->arr[i] = S->arr[j];
                S->arr[j] = tmp;
            }
        }
    }
}

int main(){
    SetType S; initSet(&S);
    SetType B; initSet(&B);

    // srand(time(NULL));
    randAdd(&S);randAdd(&B);
    upSort(&S);upSort(&B);

    // addElem(&S,10);addElem(&S,15);addElem(&S,20);
    // for(int i=0;i<9;i++)addElem(&B,i+1);

    // printf("%d",subset(&S,&B));

    // removeElem(&B,3);
    printf("A set : ");print(&S);
    printf("B set : ");print(&B);



    UnionSet(&S,&B);
    SetType U = UnionSet(&S,&B);
    printf("U set : "); print(&U);

}