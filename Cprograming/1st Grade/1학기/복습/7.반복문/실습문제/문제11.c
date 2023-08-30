#include  <stdio.h>
int main(){
    
    int n,a,b,c,spn=0;
    scanf("%d",&n);
    for(a=1;a<=6;a++){
        for(b=1;b<=6;b++){
            for(c=1;c<=6;c++){
                if((a+b+c) == n ){
                    if(spn!=0)
                        printf("\n");
                    spn++;
                    printf("%d %d %d",a,b,c);
                }
                    
            }
        }
    }
}


