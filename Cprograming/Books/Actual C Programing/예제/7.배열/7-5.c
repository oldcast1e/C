#include  <stdio.h>
int main(){
    
    int N[10],C[6]={0,};//0~5사이의 정수 10개

    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
        if(N[i]==0)
            C[0] ++;
        else if(N[i]==1)
            C[1] ++;
        else if(N[i]==2)
            C[2] ++;
        else if(N[i]==3)
            C[3] ++;
        else if(N[i]==4)
            C[4] ++;
        else if(N[i]==5)
            C[5] ++;
    }//0~5사이의 숫자가 각각 몇번 입력되었는지 출력

    for(int j=0;j<6;j++){
        printf("%d ",C[j]);
    }

}
