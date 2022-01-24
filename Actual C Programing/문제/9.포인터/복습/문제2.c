#include  <stdio.h>
int main(){
    char ch[20]={0};
    char *pch = ch;
    int cnt=0,key=0,rst,brv=0;
    while(1){
        scanf("%c",pch+cnt);
        if(*(pch+cnt) =='\n') break;
        cnt++;
    }
    // printf("cnt = %d\n",cnt);
    for(int i=cnt;i>=0;i--){
        if(*(pch+i)== '#'){
            key = 1;
            for(int j=i-1;j>=0;j--){
                if(*(pch+j)=='#') key = 0;
                // printf("j=%d\n",j);
            }
        }
        if(key==1){
            printf("i=%d\n",i);
            rst = i;
            brv = 1;
            break;
        } 
    }
    for(int i=rst-1;i>=0;i--)printf("%c",*(pch+i));
}
//duck#dduckk#popo
//cnt = 16;
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//첫번째 #이전의 입력된 글자 출력
//1~CNT까지 입력됨
//마지막부터 훝어서 해당 숫자 전부터 앞으로 #이 없으면 해당 번호 저장
