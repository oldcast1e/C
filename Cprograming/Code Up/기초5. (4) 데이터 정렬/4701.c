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
    int num[10001],N,cnt=0;
    scanf("%d",&N);
    int *rst = (int*)malloc((N*(N-1)/2)*sizeof(int));

    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            rst[cnt] = num[i] + num[j];
            cnt ++;
        }
    }
    // for(int i=0;i<10;i++)rst[i] = i +1;
    for(int i=0;i<(N*(N-1)/2);i++)printf("%d ",rst[i]);
    
    quickSort(rst,0,(N*(N-1)/2)-1);printf("\n");
    for(int i=0;i<(N*(N-1)/2);i++)printf("%d ",rst[i]);
} 
/*

*/