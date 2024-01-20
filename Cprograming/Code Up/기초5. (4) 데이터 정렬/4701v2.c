#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
    int num[10001],N,pos_cnt=0,neg_cnt=0;
    scanf("%d",&N);
    int *pos = (int*)malloc((N*(N-1)/4+1)*sizeof(int));
    int *neg = (int*)malloc((N*(N-1)/4+1)*sizeof(int));

    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int rst = num[i] + num[j];
            if(rst < 0) {neg[neg_cnt] = rst;neg_cnt++;}
            if(rst >= 0) {pos[pos_cnt] = rst;pos_cnt++;}
        }
    }

    
    quickSort(neg,0,neg_cnt-1);//printf("\n");
    quickSort(pos,0,pos_cnt-1);
    // for(int i=0;i<neg_cnt;i++)printf("%d ",neg[i]);
    // printf("\n");
    // for(int i=0;i<pos_cnt;i++)printf("%d ",pos[i]);
    int val = abs(neg[neg_cnt-1])<abs(pos[0])?neg[neg_cnt-1]:pos[0];
    printf("%d",val);
    // for(int i=0;i<(N*(N-1)/2);i++)printf("%d ",rst[i]);
} 
/*

*/