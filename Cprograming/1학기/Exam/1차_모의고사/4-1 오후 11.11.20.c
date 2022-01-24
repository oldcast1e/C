#include  <stdio.h>
int main(){

    int n,m,a,key=0;
    int upcnt,udcnt;
    while(1){
        scanf("%d",&n);
        if(n<=1)
            break;
        else{
            upcnt=0,udcnt=0;
            m = n;
            a = 2;
            while(1){
                if(m%a==0){
                    upcnt +=1;
                    m/=a;


                }
                else{
                    if(m%(a-1)==0){
                        printf("%d %d ",a,upcnt);
                    }
                    
                    a +=1;
                    if(m<=1)
                        break;
                }
            }
        }
    }

}


