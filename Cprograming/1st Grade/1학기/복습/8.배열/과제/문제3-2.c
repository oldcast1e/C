#include  <stdio.h>
int main(){
    
    int F,R,M;
    int tmp,save;
    int num[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
    scanf("%d %d %d",&F,&R,&M);
    save  = num[R];
    for(int i=0;i<M-1;i++){//4
        num[R-i] = num[R-i-1];
    }
    num[R-M+1]= save;
    for(int i=0;i<20;i++){//4
        printf("%d ",num[i]);
    }
    
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
