#include  <stdio.h>
int main(){
    
    int N,inp;
    int now,bef;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&inp);
        if(i==0){
            now = inp;
            bef = inp;
        }

        else if(i>0){
            if(inp>now){
                bef = now;
                now = inp;
            }
            else if(now>bef && bef<inp)
                bef = inp;      
        }
    }
    printf("%d\n%d",now,bef);

}
