#include  <stdio.h>
int main(){

    int n,m,cnt;
    int maxcntnum=-1,maxcnt=-1;
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++){
        cnt =0;
        for(int j=1;j<=i;j++){
            if(i%j==0)
                cnt++;
        }
        if(cnt>maxcnt){
            maxcnt = cnt;
            maxcntnum = i;
        }
    }
    printf("%d %d",maxcntnum,maxcnt);
    
}