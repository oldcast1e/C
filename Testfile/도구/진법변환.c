#include  <stdio.h>
int main(){
    int N,M;
    char set;
    printf("<계산 할 진수계를 선택하세요>\n\n>  8진수: o\n> 10진수: d\n> 16진수: x\n");
    scanf("%c",&set);

    printf("변환 할 숫자를 입력하세요:");
    
    if(set == 'd'){
        scanf("%d",&N); 
        
        printf("10진수 -> 8진수 : %o\n",N);
        printf("10진수 -> 16진수 : %x",N);
    }
    else if(set == 'o'){
        
        scanf("%o",&N);
        printf("8진수 -> 10진수 : %d\n",N);
        printf("8진수 -> 16진수 : %x",N);  
    }
    if(set == 'x'){
        scanf("%x",&N);
        printf("16진수 -> 8진수 : %o\n",N);
        printf("16진수 -> 10진수 : %d",N); 
    }
   
    
    


}
