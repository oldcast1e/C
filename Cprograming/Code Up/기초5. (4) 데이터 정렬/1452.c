#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void quickSort(int arr[], int L, int R){
    int left = L, right = R,tmp;
    int Piv = arr[(L+R)/2];
    do{
        while(arr[left] < Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(arr[right] > Piv) right--;
        //right Piv보다 작은 값을 만나거나 피벗(Piv)을 만날때 까지
        if( left <= right){
            tmp = arr[left];
            arr[left]= arr[right];
            arr[right] = tmp;

            left++; right --;
        }
    } while(left <= right);

    if(L < right) quickSort(arr,L,right);
    if(R > left) quickSort(arr,left,R);
}

int main(){
    int n,num[10001];
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    quickSort(num,0,n-1);

    for(int i=0;i<n;i++)printf("%d ",num[i]);
}
/*
5
7
3
10
2
1
*/