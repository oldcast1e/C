#include  <stdio.h>
int main(){
    
    int n,sum;
    scanf("%d",&n);
    while(1){
        sum = 0;
        while(n>0){
            sum += n%10;
            n /=10;
        }
        if(sum>=10){
            n = sum;
            continue;
        }
        else if(sum<10)
            break;
        
    }
    printf("%d",sum);
}

// if(spn!=0)
//             printf("\n");
//         spn++;
