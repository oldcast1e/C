#include  <stdio.h>
int apr[3] = {0};
int main(){    
    int changenum;
    int nomalnumber;
    int sum = 0,dif;
    scanf("%d",&nomalnumber);
    for(int i=1;i<=nomalnumber;i++){
        if(i<100) sum ++;
        else if(100<=i&& i<1000){
            int cnt = i;
            for(int j=0;j<3;j++){
                apr[j] = cnt%10;
                cnt/=10;
            }
            if((apr[1]-apr[0])==(apr[2]-apr[1]))sum++;
        } 
    }
    printf("%d",sum);
}
//일단 100까지의 한수를 구해보자
//N = 1000보다 작거나 같은 수

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

