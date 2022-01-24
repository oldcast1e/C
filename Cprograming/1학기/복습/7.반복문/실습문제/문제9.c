#include  <stdio.h>
int main(){
    
    int n,cnt=0,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i<10){
            if(i==3)
                cnt++;
        }
        else{
            m = i;
            while(m>0){
                if(m%10==3)
                    cnt++;
                m/=10;
            }
        }
    }
    printf("%d",cnt);
}

// if(spn!=0)
//             printf("\n");
//         spn++;
