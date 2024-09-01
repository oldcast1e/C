#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//4개의 변수 중 가장 큰 값을 찾는 알고리즘

int max4(int a,int b,int c,int d){
    int val[4]={a,b,c,d};
    int max;
    printf("세 정수의 최대값 구하기\n");
    for(int i=0;i<4;i++){
        printf("%c의 값: ",(65+i));scanf("%d",&val[i]);
        if(i==0)max = val[i];
        else if(val[i] > max) max = val[i];
    }
    return max;
}
int main(){
    int a,b,c,d;
    int max = max4(a,b,c,d);
    printf("최대값은 %d 입니다.",max);

}
