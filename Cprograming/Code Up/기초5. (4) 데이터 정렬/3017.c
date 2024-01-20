#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
        v
//quick 정렬 (퀵 정렬)
void quickSort(int arr[][3], int L, int R){
    int left = L, right = R,tmp_A,tmp_B;
    int Piv = arr[(L+R)/2][0];
    do{
        while(arr[left][0] > Piv) left++;
        //left가 Piv보다 큰 값을 만나거나 피벗(Piv)을 만날때 까지
        while(arr[right][0] < Piv) right--;
        //right Piv보다 작은 값을 만나거나 피벗(Piv)을 만날때 까지
        if( left <= right){
            tmp_A = arr[left][0];
            arr[left][0] = arr[right][0];
            arr[right][0] = tmp_A;

            tmp_B = arr[left][1];
            arr[left][1] = arr[right][1];
            arr[right][1] = tmp_B;

            left++; right --;
        }
    } while(left <= right);

    if(L < right) quickSort(arr,L,right);
    if(R > left) quickSort(arr,left,R);
}

int main(){
    int N;
    int num[1000][2];
    scanf("%d",&N);
    // for(int i=0;i<(int)strlen(arr);i++)
    
    for(int i=0;i<N;i++){scanf("%d %d",&num[i][0],&num[i][1]);}
    quickSort(num,0,N-1);
    
    for(int i=0;i<N;i++)printf("%d %d %d\n",i+1,num[i][0],num[i][1]);

    
} 
/*
첫째 줄에 학생수 n(번호:1~n)가 입력된다. (1 <= n <= 1,000)

5
100 90
90 100
80 80
80 90
60 50
*/