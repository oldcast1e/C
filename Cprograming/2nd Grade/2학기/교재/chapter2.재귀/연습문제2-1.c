#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int arr[10], n= 10;


int arrayMax(int *arr,int n){ //비재귀적
    int currentMax =  arr[0];
    for(int i = 1; i<n ; i++){
        if(arr[i] > currentMax){
            currentMax = arr[i];
        }
    }
    return currentMax;
}

int max(int max_value,int cnt){
    if(cnt >= n) return max_value;
    else if(arr[cnt] > max_value) max_value = arr[cnt];

    return max(max_value,cnt+1);
    // max(arr,n,max,cnt++);
}

int min(int min_value,int cnt){
    if(cnt >= n) return min_value;
    else if(arr[cnt] < min_value) min_value = arr[cnt];

    return min(min_value,cnt+1);
}

void currentMaxMin(int *arr){
    printf("Max = %d",max(arr[0],0)); printf("\n");
    printf("Min = %d",min(arr[0],0));
}

int main(){
    srand(time(NULL));
    for(int i=0;i<10;i++) arr[i] = rand()%10;
    for(int i=0;i<10;i++) printf("%d ",arr[i]); printf("\n");
    // printf("Max = %d",arrayMax(arr,10));


    // printf("Max = %d",max(arr[0],0)); printf("\n");
    // printf("Min = %d",min(arr[0],0));
    currentMaxMin(arr);
}