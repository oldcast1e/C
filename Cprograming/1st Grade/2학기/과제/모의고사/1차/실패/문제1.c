#include  <stdio.h>

void input(int *p, int M){

    for(int i=0;i<M;i++){
        scanf("%d",(p+i));
    }
}
int *sel_max(int *in,int M){

    int rank[101]={0};
    int rst;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(i!=j){
                if(*(in+i)==*(in+j)) rank[i] ++;
            }
        }
    }
    int max = rank[0];

    for(int i=0;i<M;i++){
        if(rank[i]>max){
            max = rank[i];
            rst = i;
        }
    }
    return in+rst;//출력할 정수 위치 반환
}
void output(int *p, int N){//여기서 포인터는 맥스 = 최대값의 위치
    for(int i=0;i<N;i++){
        printf(" %d",*(p+i));
    }
    
}
int main(void){
    int in[100], out[100], *max, i, N, M;
    scanf("%d %d", &N, &M); 
    for (i=0; i<N; i++){
        input(in, M); 
        max = sel_max(in, M); 
        out[i] = *max;
    }
    output(out, N); return 0;
}
/*
3 5 
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5
*/