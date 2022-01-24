#include  <stdio.h>
int main(){
    
    int n,m,tmp,rst=1,spn=0;
    scanf("%d %d",&n,&m);

    if(n>m){
        tmp = n;
        n = m;
        m = tmp;
    }

    for(int i=n;i<=m;i++){
        rst = 1;
        if(spn!=0)
            printf("\n");
        spn++;

        printf("%d!=1",i);
        for(int k=1;k<i;k++)
            printf("*%d",k+1);

        for(int r=1;r<=i;r++)
            rst *=r;
        printf("=%d",rst);

    }
}


