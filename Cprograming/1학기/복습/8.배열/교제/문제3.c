#include  <stdio.h>
int main(){
    
    int spn = 0;
    char U[5],tmp;
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
        for(int j=3;j>=0;j--){
            U[j+1] = U[j]; 
        }
        U[0] = tmp;
    }

}


