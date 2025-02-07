#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rbinaryFind(int *num, int left, int right ,int key){
    if(left > right) return right; // 종료 조건: 키가 없을 경우 가장 가까운 작은 값 반환

    int middle = (left + right)/ 2;

    if(num[middle] == key) return middle; // 키를 찾은 경우 위치 반환

    if(key < num[middle]) 
        return rbinaryFind(num, left, middle - 1, key);
    else 
        return rbinaryFind(num, middle + 1, right, key);
}

int main(){
    // int n, key, result; 
    // scanf("%d %d", &n, &key);
    // int *num = (int*)malloc(sizeof(int) * n);
    
    // for(int i = 0; i < n; i++) 
    //     scanf("%d", &num[i]);

    // if(key < num[0]) 
    //     result = -1; // 모든 값이 키보다 클 경우 -1 반환
    // else if(key > num[n-1]) 
    //     result = n - 1; // 모든 값이 키보다 작을 경우 마지막 인덱스 반환
    // else 
    //     result = rbinaryFind(num, 0, n - 1, key);
    
    printf(" %d", 17012687%7);
}
