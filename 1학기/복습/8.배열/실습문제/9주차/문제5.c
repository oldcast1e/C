#include  <stdio.h>
int main(){
    
    char U[5],tmp;
    int spn = 0;
    for(int i=0;i<5;i++){
        scanf("%c",&U[i]);
    }
    for(int i=0;i<5;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        for(int k=0;k<5;k++){
            printf("%c",U[k]);
        }

        tmp = U[4];
        for(int j=4;j>=1;j--){
            U[j] = U[j-1];
        }
        U[0] = tmp;
        
    }

}


