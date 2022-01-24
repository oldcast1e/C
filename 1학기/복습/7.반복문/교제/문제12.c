#include  <stdio.h>
int main(){
    
    int N,pf=2,cnt=0,spn=0;
    int key;
    scanf("%d",&N);
    while (N>0)
    {
        if(N%pf==0){
            cnt++;
            N/=pf;
            key = 1;
        }
        else{
            if(key ==1){
                if(spn!=0)
                    printf("\n");
                spn++;
                printf("%d %d",pf,cnt);
                key = 0;
                if(N==1)
                    break;
            }
            cnt=0;
            pf++;
        }
    }
}
