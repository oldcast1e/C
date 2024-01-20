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
    
    for(int i=0;i<N;i++)printf("%d %d %d\n",num[i][2],num[i][0],num[i][1]);

    
} 
/*
첫째 줄에 학생수 n(번호:1~n)가 입력된다. (1 <= n <= 1,000)

5
100 90
90 100
80 80
80 90
60 50

10
84 94
75 90
95 76
85 95
85 92
79 94
90 86
99 95
82 93
98 97

8 99 95
10 98 97
3 95 76
7 90 86
5 85 92
4 85 95
1 84 94
9 82 93
6 79 94
2 75 90

8 99 95
10 98 97
3 95 76
7 90 86
4 85 95
5 85 92
1 84 94
9 82 93
6 79 94
2 75 90

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
*/