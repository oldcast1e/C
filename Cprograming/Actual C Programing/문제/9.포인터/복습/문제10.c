#include  <stdio.h>
char arra[6],arrb[6];
char *parra = arra,*parrb = arrb;
void strcopy(){
    for(int i=0;i<6;i++)*(arra+i) = *(arrb+i);
}
int main(){
    for(int i=0;i<6;i++){
        scanf("%c",(parrb+i));
    }
    strcopy();
    for(int i=0;i<6;i++){
        printf("%c",*(parra+i));
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//포인터를 이용하여 문자 6개를 복사하는 함수를 만들고 출력하라

