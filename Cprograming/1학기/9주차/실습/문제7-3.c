#include  <stdio.h>
int main(){
    
    int n,num,cnt;
    
    int D[10];
    int X[10];
    for(int i=0;i<10;i++){
        scanf("%d",&D[i]);
    }

    for(int i=0;i<10;i++){
        num = D[i];
        cnt = 0;
        for(int j=0;j<10;j++){
            if(num == D[i])
                cnt++;
        }
        if(cnt==1){
            printf("%d %d",D[i],cnt);
        }
        else{
            
        }
        
    }

}


