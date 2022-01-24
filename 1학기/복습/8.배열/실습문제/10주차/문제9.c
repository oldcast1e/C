#include  <stdio.h>
int main(){
    
    int n,rst=0;
    scanf("%d",&n);
    int N[10];
    for(int i=0;i<n;i++){
        scanf("%d",&N[i]);
    }
    for(int i=0;i<n;i++){
        rst += N[i];
        rst*=10;
    }
    printf("%d",rst/10);
}


