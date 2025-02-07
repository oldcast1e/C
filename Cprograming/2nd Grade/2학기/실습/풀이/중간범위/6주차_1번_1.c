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

    // if(key < num[middle]){right = middle - 1;}
    // if(key > num[middle]){left = middle + 1;}

    // printf("left = %d | right = %d\n",left,right);
    if(num[left] > key ) {return left-1;}//printf("check num[%d]\n",num[left]); 

    // return rbinaryFind(num,left,right,key);
    // for(int i=left ;i<= right ;i++){

    // }

}

int main(){
    int n,key,result; scanf("%d %d",&n,&key);
    int *num = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    if(key < num[0]) result = -1; //인덱스 반환!!
    else if(key > num[n-1]) result = n-1; //인덱스 반환!!
    else result = rbinaryFind(num,0,n-1,key);

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

>>키보다 모두 큰 경우
8 33
34 35 36 37 38 39 40 41

>>키보다 모두 작은 경우
8 33
1 2 3 4 5 6 7 8
*/