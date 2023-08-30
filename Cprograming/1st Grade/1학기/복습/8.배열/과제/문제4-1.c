#include  <stdio.h>
int main(){
    
    int N,tmp;
    int num[20];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    for(int i=N-1;i>=0;i--){
        printf("%d ",num[i]);
    }
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
