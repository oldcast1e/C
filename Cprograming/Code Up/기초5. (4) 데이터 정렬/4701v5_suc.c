#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void quickSort(int arr[], int L, int R){
    int left = L, right = R,tmp;
    int Piv = abs(arr[(L+R)/2]);
    do{
        while(abs(arr[left]) < Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(abs(arr[right]) > Piv) right--;
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
    int num[100001],N,rst[2];
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    
    quickSort(num,0,N-1);

    int val;
    for(int i=0;i<N-1;i++){
        if(i==0){
            val = abs(num[0] + num[1]);
            rst[0] = num[i]; 
            rst[1] = num[i+1];
        }
        else if(val > abs(num[i]+num[i+1])){
            val = abs(num[i]+num[i+1]);
            
            rst[0] = num[i]; 
            rst[1] = num[i+1];
        }
    }
    // for(int i=0;i<N;i++)printf("%d ",num[i]);
    if(rst[0] > rst[1]){
        int tmp = rst[0];
        rst[0] = rst[1]; rst[1] = tmp;
    }
    printf("%d %d",rst[0],rst[1]);
} 
/*

*/