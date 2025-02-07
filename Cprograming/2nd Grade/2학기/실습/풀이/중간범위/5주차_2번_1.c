#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*
부리스트의 수들 중 1개의 위치를 무작위로 선택하여 pivot의 위치로 정한다.
(즉, 입력배열의 l과 r 사이의 1개위치를 랜덤하게 선택)
*/
int findPivot(int l,int r){
    //l:left, r:right
    /*
    2,9 -> 1~10
    (0~7) + 2

    rand()%7 => 0~6
    rand()%7+2 => 2~9
    */

   /*주의하기!!!!!*/
    // srand(time(NULL));
    if (r-l <= 1) return l;

    int rst = (rand()%(r-l))+l;
    return rst;
}

void swap(int *a,int *b){
    int tmp;
    tmp = *a; *a = *b; *b = tmp;
}

/*
inPlacePartition의 반환값은 두 인덱스 (a, b)로, 그 의미는 분할 결과, 
배열의 l번째 수부터 a – 1번째 수는 pivot보다 작은 값을, 
배열의 a번째부터 b번째 수는 pivot과 같은 값을, 
b+ 1번째부터 r번째 수는 pivot보다 큰 값을 가진다는 것이다
(즉, 이후 호출되는 재귀함수는l부터 a – 1까지 부배열에 대해서와 b + 1부터 r까지의 
부배열에 대해서 다루고, pivot과 같은 값들인 a부터 b번째 값들은 재귀에서 제외된다).
*/
int inPlacePartition(int *num,int l, int k, int r){
    int i,j,p;

    i = l;
    j = r - 1;//배열은 0부터 시작
    p = num[k]; //피벗 위치의 데이터
    // printf("[%d] <-> [%d]\n",num[r],num[k]);
    swap(&num[r],&num[k]);

    while(i<=j){
        while(i <= j && num[i] <= p){
            i += 1;
        }
        while(i <= j && num[j] >= p){
            j -= 1;
        }
        if(i < j) swap(&num[i],&num[j]);
    }
    swap(&num[i],&num[r]);
    return i;
}

void quickSort(int *num,int l,int r){
    //입력받은 초기 배열과 각 위치 l(left), r(right)인자를 받음
    // => 재귀적 실행
    int k,a,b;
    if(l >= r) return;
    
    k = findPivot(l,r);
    // printf("pivot = %d\n",k);
    a = b = inPlacePartition(num,l,k,r);
    
    quickSort(num,l,a-1);
    quickSort(num, b+1, r); //이거 아님->quickSort(num,b+1,l);
    
}

int main(){
    int n; scanf("%d",&n);
    int *num = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    
    srand(time(NULL));
    quickSort(num,0,n-1);
    for(int i=0;i<n;i++)printf(" %d",num[i]);
}

/*
3
4 9 1


8
73 65 48 31 29 20 8 3
*/