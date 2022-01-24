#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//4개의 변수 중 가장 작은 값을 찾는 알고리즘

int min4(int a,int b,int c,int d){
    int val[4]={a,b,c,d};
    int min;
    printf("네 정수의 최솟값 구하기\n");
    for(int i=0;i<4;i++){
        printf("%c의 값: ",(65+i));scanf("%d",&val[i]);
        if(i==0)min = val[i];
        else if(val[i] < min) min = val[i];
    }
    return min;
}
int main(){
    int a,b,c,d;
    int min = min4(a,b,c,d);
    printf("최솟값은 %d 입니다.",min);

}
