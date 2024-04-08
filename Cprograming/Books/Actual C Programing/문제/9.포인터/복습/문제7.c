#include  <stdio.h>
void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp; 
}
int main(){
    int N,arr[50]={0},a,b;
    int *parr  = arr;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",(parr+i));
    }
    scanf("%d %d",&a,&b);
    swap((parr+a),(parr+b));
    for(int i=0;i<N;i++){
        printf("%d ",*(parr+i));
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//n개의 정수를 입력받아 배열에 저장한 후(50개 까지)
// 다시 배열에 값을 교환하고 싶은 서로 다른 첨자 a와b를 입력받는다