#include  <stdio.h>
int main(){
    
    int N[5],spn=0;
    double sum = 0;
    for(int i=0;i<5;i++){
        scanf("%d",&N[i]);
        sum += N[i];
    }
    sum /=5;
    for(int i=0;i<5;i++){
        
        if(N[i]>sum){
            if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
                printf("\n");
            spn++;//줄 띄움 변수 증가
            printf("%d",N[i]);
        }
            
    }
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
