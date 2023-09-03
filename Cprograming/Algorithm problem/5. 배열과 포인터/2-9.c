#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int arr[] = {1,2,3,4,5};
    iny *parr = arr;

    int arrNum = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<arrNum;i++) printf("%d\n",*(parr+i));
}