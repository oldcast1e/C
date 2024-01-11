#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a,int b,int c){
    // return(a>b?b:a);
    int rst = a>b&&c>b ? b :((b>c&&a>c)?c:a);
    return rst;
}

void cal(int *a,int *b,int *c){
    if(*a<=0) *a = 1001;
    if(*b<=0) *b = 1001;
    if(*c<=0) *c = 1001;
}
int main(){
    int n,g,cnt=1001;
    int num[100]={0};
    scanf("%d %d",&n,&g);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int k=0;k<n/g;k++){
        cal(&num[g*k], &num[g*k+1], &num[g*k+2]);
        num[k] = min(num[g*k], num[g*k+1], num[g*k+2]);
        // int rst = num[g*k]>num[g*k+1]&&num[g*k+2]>num[g*k+1] ? num[g*k+1] :((num[g*k+1]>num[g*k+2]&&num[g*k]>num[g*k+2])?num[g*k+2]:num[g*k]);
        // printf("%d ",rst);
        printf("%d ",num[k]);
    }
    // printf(">%d",num[5]);
} 
/*
5 3
1 3 5 4 2 

6 3
1 3 5 4 2 7

n개의 데이터를 배열에 입력 받은 후,

g/3개씩 묶어 비교한 후, 작은 값만 들어간 배열을 만들고 출력해보자.

6개의 데이터가 다음과 같이 입력되었을 때,
1 2 3  
4 5 6

3개씩 묶어 비교한 후, 작은 값만 들어간 배열을 만들어
아래와 같이 출력하면 된다.

1 4
*/