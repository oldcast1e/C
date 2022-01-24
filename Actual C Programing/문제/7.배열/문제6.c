#include  <stdio.h>
int main(){
    
    int N[10],key,cnt;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
    }

    for(int i=0;i<10;i++){

        key = 0;
        cnt =0;

        if(i>0){
            for(int j=0;j<i;j++){

            if(N[i]==N[j])
                key =1;
        }
        }
        if(key==0){
            for(int k=0;k<10;k++){
                if(N[i]==N[k])
                    cnt++;
            }
            printf("%d %d\n",N[i],cnt);
        }
    
    }
}
