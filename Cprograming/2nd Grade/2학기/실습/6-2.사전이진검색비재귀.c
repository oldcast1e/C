#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int rbinaryFind(int *num, int left, int right ,int key){
    if(left > right) return right;
    int middle = (left + right)/ 2; //3
    if(num[middle] == key) return middle;
    else{
        if(key < num[middle])return rbinaryFind(num,left,middle - 1,key);
        if(key > num[middle])return rbinaryFind(num,middle + 1,right,key);
    }
    if(num[left] > key ) {return left-1;}//printf("check num[%d]\n",num[left]); 

    return -1;
}

int binaryFind(int *num, int left, int right ,int key){

    /**
    key보다 같거나 큰 값 중, 가장 작은 위치
     */
    int middle;
    if(num)
    while(1){
        if(left > right) return left; //!!!이거 아님  ->>> if(left >= right) return right;
        //0 7 => 0 2 => 0 1
        middle = (left + right)/ 2; 
        if(num[middle] == key) return middle;
        else{
            if( key< num[middle] ) right = middle - 1;
            if( key > num[middle] ) left = middle + 1;
        }
    }
    return 0;
}

int main(){
    int n,key,result; scanf("%d %d",&n,&key);
    int *num = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    if(key <= num[0]) result = 0; //key보다 모두 작은 경우: x ≥ k 를 만족하는 사전의 키 x 중 가장 작은 값의 위치
    else if(key >= num[n-1]) result = n; //key보다 모두 큰 경우 : 
    else result = binaryFind(num,0,n-1,key);

    printf(" %d",result);
}

/*
8 -7
-92 -31 -7 4 14 20 29 44
=> 2

>>>> 키가 없는 경우
8 33
-92 -31 -7 4 14 20 29 44
=> 6

>>키보다 모두 작은 경우 8
8 55
-92 -31 -7 4 14 20 29 44

8 55
1 2 3 4 5 6 7 8

>>키보다 모두 큰 경우 0
8 -100
-92 -31 -7 4 14 20 29 44

8 33
34 35 36 37 38 39 40 41

>> 모두 키와 같은 경우
8 33
33 33 33 33 33 33 33 33
*/