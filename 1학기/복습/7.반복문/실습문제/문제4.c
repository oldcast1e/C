#include  <stdio.h>
int main(){
    
    int n,m,tmp;
    scanf("%d %d",&n,&m);
    if(n>m){//n<m이도록 만듦
        tmp = n;
        n = m;
        m = tmp;
    }
    for(int i=n;i>=1;i--){
        if(m%i==0 && n%i==0){
            printf("%d",i);
            break;

        }
    }
}
