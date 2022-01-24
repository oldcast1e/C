#include  <stdio.h>
int main(){
    
    char U[10];
    for(int i=0;i<10;i++){
        scanf("%c",&U[i]);
    }
    for(int i=0;i<10;i++){
        if('A'<=U[i] && U[i]<='Z')
            printf(" %c",U[i]);
    }

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
