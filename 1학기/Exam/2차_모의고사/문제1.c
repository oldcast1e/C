#include  <stdio.h>
int main(){
    
    int N[3],a,b,c;
    int  tmp,spn=0;
    while(1){
        for(int i=0;i<3;i++){
            scanf("%d",&N[i]);
            if(i==0) a= N[i];
            else if(i==1) b = N[i];
            else if(i==2) c = N[i];
        }
        

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(N[j]<N[j+1]){
                    tmp = N[j];
                    N[j]= N[j+1];
                    N[j+1] = tmp;
                }
            }
        }
        if(a==0 && b==0 && c==0) break;
        
        for(int i=0;i<3;i++){
            printf("%d ",N[i]);
        }
        printf("\n");
   
    }
}



