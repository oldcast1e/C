#include  <stdio.h>
int main(){
    
    int N[5],tmp,spn=0;
    for(int i=0;i<5;i++){
        scanf("%d",&N[i]);
    }

    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            if(N[i]>N[i+1]){
                tmp = N[i];
                N[i] = N[i+1];
                N[i+1] = tmp;
            }
        }
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        for(int i=0;i<5;i++){
            printf("%d ",N[i]);
        }
    }

    


}


