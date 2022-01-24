#include  <stdio.h>
int main(){
    
    int N,M,cnt=0;
    int num[100];
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i!=j){

                if((num[i]+ num[j])==M)
                    cnt++;
            }
        }
    }
    printf("%d",cnt/2);
    
}
