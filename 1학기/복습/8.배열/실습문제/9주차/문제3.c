#include  <stdio.h>
int main(){
    
    int N[5];
    
    for(int i=0;i<5;i++){
        scanf("%d",&N[i]);
    }
    int max = -100000,bef = -100000;
    for(int i=0;i<5;i++){
        if(N[i]>max){
            bef = max;
            max = N[i];
        }
        else if(max>=N[i] && N[i]>bef)
            bef = N[i];
    }
    printf("%d\n%d",max,bef);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
