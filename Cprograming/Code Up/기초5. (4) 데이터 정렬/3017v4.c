#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void swap(int arr[][3],int left,int right,int rank){
    int tmp;
    tmp = arr[left][rank];
    arr[left][rank] = arr[right][rank];
    arr[right][rank] = tmp;
}
//quick 정렬 (퀵 정렬)
void quickSort(int arr[][3], int L, int R,int key){
    int left = L, right = R,tmp_A,tmp_B;
    int Piv = arr[(L+R)/2][key];
    do{
        while(arr[left][key] > Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(arr[right][key] < Piv) right--;
        //right Piv보다 작은 값을 만나거나 피벗(Piv)을 만날때 까지
        if( left <= right){
            swap(arr,left,right,0);
            swap(arr,left,right,1);
            swap(arr,left,right,2);

            left++; right --;
        }
    } while(left <= right);

    if(L < right) quickSort(arr,L,right,key);
    if(R > left) quickSort(arr,left,R,key);
}

void quickSort_R(int arr[][3], int L, int R,int key){
    int left = L, right = R,tmp_A,tmp_B;
    int Piv = arr[(L+R)/2][key];
    do{
        while(arr[left][key] < Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(arr[right][key] > Piv) right--;
        //right Piv보다 작은 값을 만나거나 피벗(Piv)을 만날때 까지
        if( left <= right){
            swap(arr,left,right,0);
            swap(arr,left,right,1);
            swap(arr,left,right,2);

            left++; right --;
        }
    } while(left <= right);

    if(L < right) quickSort_R(arr,L,right,key);
    if(R > left) quickSort_R(arr,left,R,key);
}

int main(){
    int N;
    int num[1000][3];
    scanf("%d",&N);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<N;i++){
        num[i][2] = i + 1;
        scanf("%d %d",&num[i][0],&num[i][1]);
    }
    quickSort(num,0,N-1,0);

    int tR=0,tL=0;
    for(int i=0;i<N-1;i++){
        if(num[i][0]==num[i+1][0]){
            tR ++;
        }
        else if(num[i][0] != num[i+1][0]){
            quickSort(num,tL,tR,1);
            tL = i+1;
            tR = i+1;
        }
    }

    tR=0,tL=0;
    for(int i=0;i<N-1;i++){
        if(num[i][0]==num[i+1][0] && num[i][1]==num[i+1][1]){
            // printf(">>>%d %d %d\n",num[i][2],num[i][0],num[i][1]);
            tR ++;
        }
        if((num[i][0] !=num[i+1][0] || num[i][1] != num[i+1][1]) || tR >= N-1){
            // printf(">>>%d %d %d\n",num[i][2],num[i][0],num[i][1]);
            // if(tR >= N-1) tR ++;
            quickSort_R(num,tL,tR,2);
            
            tL = i+1;
            tR = i+1;
        }
        // printf("[tL = %d | tR = %d]\n",tL,tR);
    }
    
    for(int i=0;i<N;i++)printf("%d %d %d\n",num[i][2],num[i][0],num[i][1]);

    
} 
/*
5
10 10
20 20
10 10
20 20
10 10

2 20 20
4 20 20
5 10 10
1 10 10
3 10 10

2 20 20
4 20 20
1 10 10
5 10 10
3 10 10
*/