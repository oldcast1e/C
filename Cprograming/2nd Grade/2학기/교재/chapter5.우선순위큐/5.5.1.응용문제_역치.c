#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculate(int *num, int size){
    int cnt = 0;
    for(int i=0;i<size;i++){
        //num[i] > num[j] && i < j
        for(int j=i+1;j<size;j++){
            if(num[i] > num[j] && (i < j)) cnt ++;
        }   
    }
    return cnt;
}

int main(){
    // int arr[] = {2, 3, 8, 6, 1};//임의의 배열
    int arr[] = {5, 4, 3, 2, 1};//임의의 배열
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("역치의 수: %d",calculate(arr,n));

}