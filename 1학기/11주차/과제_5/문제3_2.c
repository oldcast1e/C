#include  <stdio.h>


int multiple(int,int),maximum(int,int),digit_maximum(int);

int main(){
    
    int N,M,K;
    int max1 = -1,max2=-1;
    scanf("%d %d %d",&N,&M,&K);//N~M까지의 숫자 중 K의 배수인 수
    int rst;
    for(int i=N;i<=M;i++){
        rst = multiple(i,K);
  
        if(rst==1) max1 = digit_maximum(i);
        else max2 = maximum(i%K,max2);
            // if(i%K>max2) max2 = i%K;
    }
    printf("%d",maximum(max1,max2));
}

int multiple(int x,int y){
    if(x%y==0) return 1;
    else return 0;
}
int maximum(int x,int y){
    printf("K로 나눈 수:%d |기존의 수:%d\n",x,y);
    return (x>y?x:y);
}
int digit_maximum(int x){
    printf("K의 배수 :%d //",x);
    int max = -1;
    while(x>0){
        max = maximum(x%10,max);
        x/=10; 
    }
    printf("각 자리수 중에 가장 큰 값:%d\n",max);
    return max;
}
// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가

