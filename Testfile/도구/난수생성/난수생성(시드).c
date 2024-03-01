#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
int main(){
    int n;
    srand(time(NULL));
    for(int i=0;i<5;i++){
        
        printf("%d\n",rand());
    }
}
