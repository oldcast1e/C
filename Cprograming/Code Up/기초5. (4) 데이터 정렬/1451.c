#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *dir_a, int *dir_b){
    int cnt;
    cnt = *dir_a;
    *dir_a = *dir_b;
    *dir_b = cnt;
}

int main(){
    int n;
    int num[100001];
    //fgets(arr, 101, stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i] > num[j]) swap(&num[i],&num[j]);
        }
    }
    for(int i=0;i<n;i++)printf("%d\n",num[i]);  
}