#include<stdio.h>
 
int main(){
 
    int N,M;
    int arr[10000001] = {};
    int num;
 
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        arr[num] = 1;
    }
    
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        printf("%d ", arr[num]);
    }
    
 
    return 0;
    
 
}
