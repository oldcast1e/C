#include  <stdio.h>
int main(){
    char arr[1000001];
    char rst;
    int alb[26]={0},cnt = 0,key = 1,max;
    while(1){
        scanf("%c",&arr[cnt]);
        if(arr[cnt]=='\n') break;

        if((int)arr[cnt]>=97) alb[(int)arr[cnt]-97] ++;
        else alb[(int)arr[cnt]-65] ++;
        cnt ++;//엔터가 입력되기전까지 입력한 문자의 수
    }
    max = alb[0];
    rst = 65;
    // rst = arr[0];
    for(int i=1;i<26;i++){
        if(alb[i]>max){
            max = (int)alb[i];
            rst = i+65;
            key = 1;
            // printf("i = %d\n",i);
        }
        else if(alb[i]==max){
            // printf("<%d>\n",i);
            key = 0;
        }
    }
    if(key == 1) printf("%c",rst);
    else if (key ==0)printf("?");

    // printf("\nkey = %d\n",key);
    // for(int i=0;i<26;i++){
    //     printf("%d",alb[i]);
    // }
}//
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

