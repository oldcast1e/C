#include  <stdio.h>
int main(){
    
    int n,sum=0;
    scanf("%d",&n);

    for(int i=1;;i++){
        
        sum += i;
        if(i==n)
            break;
    }
    printf("%d",sum);
    
}

// if(spn!=0)
//             printf("\n");
//         spn++;
