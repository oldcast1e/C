#include  <stdio.h>
int main(){
    
    int n,cnt=0;
    scanf("%d",&n);
    while(n>0){
        if(n%10==3)
            cnt++;
        n/=10;
    }
    printf("%d",cnt);

}

// if(spn!=0)
//             printf("\n");
//         spn++;
