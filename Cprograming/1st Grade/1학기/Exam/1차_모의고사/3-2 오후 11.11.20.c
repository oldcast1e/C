#include  <stdio.h>
int main(){
    int N,n,k;
    int a,b,c,d,e;//
    int sum,rvs,cnt,spcnt=0;
    //a: 입력받은 정수
    //b: 입력받은 정수의 각 자리 수 합
    //c: 입력된 정수의 자리수를 역수로 바꾼 수
    //d: 뒤집에서 만든 정수를 13으로 나눈 나머지
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++){
        sum =0;
        rvs=0;
        cnt=0;
        scanf("%d",&n);
        if(spcnt!=0){
        printf("\n");
        }
    spcnt++;
        printf("%d ",n);//a
        k = n;
        while(k>0){
            sum += k%10;
            k/=10;
        }
        printf("%d ",sum);//b
        k = n;
        while(k>0){
            rvs += (k%10);
            rvs *=10;
            k/=10;
        }
        rvs /=10;
        printf("%d ",rvs);//c 
        printf("%d ",rvs%13);
        

        

    }
}


