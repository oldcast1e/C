#include  <stdio.h>
int main(){
    
    int N,n;
    scanf("%d",&N);

    do
    {
        scanf("%d",&n);
        if(N>n)
            printf("%d<?\n",n);
        else if(N<n)
            printf("%d>?\n",n);
        else
            printf("%d==?\n",n);
    } while (n!=N);
    

}
