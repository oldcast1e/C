#include  <stdio.h>
int main(){
    
    int N[3][2];
    double sum1=0,sum2=0,spn=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&N[i][j]);
            if(j==0) sum1 += N[i][j];
            else sum2 += N[i][j];
        }
    }
    sum1 /= 3;
    sum2 /= 3;
    for(int i=0;i<3;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        for(int j=0;j<2;j++){
            if(j==0){
                if(N[i][j]<sum1)
                    printf("%d ",N[i][j]);
            }
            else{
                if(N[i][j]<sum2)
                    printf("%d ",N[i][j]);

            }
        }
    }

}


