#include  <stdio.h>
int main(){
    int n,pn,next,cnt,cnt2;
    int key;
    while(1){
        cnt = 0;
        cnt2 = 0;
        scanf("%d",&n);
        if(n<0)
            break;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                cnt++;
        }
        if(cnt==2){
            key = 1;
            next = n+1;
            while(1){
                cnt2 = 0;
                for(int j=1;j<=next;j++){
                    if(next%j==0)
                        cnt2++;
                }
                if(cnt2==2)  
                    break;
                next ++;
                
            }
            printf("%d %d\n",n,next);

        }
            
    }
    if(key==0)
        printf("none");
}


