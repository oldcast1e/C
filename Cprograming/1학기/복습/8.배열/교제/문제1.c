#include  <stdio.h>
int main(){
    
    int N[100];
    int n;
    scanf("%d",&n);
    double sum=0,avg = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&N[i]);
    }
    for(int i=0;i<n;i++){
        sum+=N[i];
    }
    avg = sum/n;
    for(int i=0;i<n;i++){
        if(N[i]>avg)
            printf("%d ",N[i]);
    }



}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
