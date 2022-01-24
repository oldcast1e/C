#include  <stdio.h>

void addArray(int *parra,int *parrb,int *prst,int size){
    for(int i=0;i<size;i++){
        *(prst+i) = *(parra+i) + *(parrb+size-i-1);
        // printf("prst = %d| parra = %d (+) paarb = %d\n",*(prst+i),*(parra+i),*(parrb+size-i-1));
    } 

}
int main(){
    int arra[20],arrb[20],rst[20]={0},n;
    int *parra = arra,*parrb = arrb,*prst = rst;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",(parra+i));
    for(int i=0;i<n;i++)scanf("%d",(parrb+i));
    
    addArray(parra,parrb,prst,n);
    for(int i=0;i<n;i++)printf("%d ",*(prst+i));



}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
//N개의 정수를 두번 입력받아 (N<=20) 역방향으로 더하여 출력하는 프로그램을 작성하라

