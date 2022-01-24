#include  <stdio.h>

int add_to_k(int *st,int *ed){
    int *i,sum=0;
    for(i=st;i<ed;i++) sum += *i;
    return sum;

}

int main(){
    int n,d[100],*st = d,*ed = (d+1),sum=0;
    int *pnum = d;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",(pnum+i));
    }
    for(int i=0;i<n;i++){
        sum += add_to_k(st,ed);
        ed ++;
        // printf("rst = %d\n",sum);
    } 
    printf("%d",sum);

}

//N개의 정수를 입력받아 (N<=100) int 형 배열 d[100]에 저장하고, 다음 수식의 값을 출력하는 프로그램을 작성하라

