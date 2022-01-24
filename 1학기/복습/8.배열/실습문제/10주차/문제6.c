#include  <stdio.h>
int main(){
    
    int N[10],rst[10];
    int cnt;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
    }
    for(int i=0;i<10;i++){
        cnt = 0;
        for(int j=0;j<10;j++){
            if(i!=j){
                if(N[i]<N[j])
                    cnt++;
            }
        }
        rst[i] = cnt;
    }
    for(int i=0;i<10;i++){
        printf(" %d",rst[i]);
    }
}


