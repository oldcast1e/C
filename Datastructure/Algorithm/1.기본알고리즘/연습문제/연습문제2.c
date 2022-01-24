#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//4개의 변수 중 가장 작은 값을 찾는 알고리즘

int min3(int a,int b,int c){
    int val[4]={a,b,c};
    int min;
    printf("네 정수의 최솟값 구하기\n");
    for(int i=0;i<3;i++){
        printf("%c의 값: ",(65+i));scanf("%d",&val[i]);
        if(i==0)min = val[i];
        else if(val[i] < min) min = val[i];
    }
    return min;
}
int main(){
    int a,b,c;
    int min = min3(a,b,c);
    printf("최솟값은 %d 입니다.",min);

}
