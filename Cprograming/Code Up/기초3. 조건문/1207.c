#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt = 0;
    int arr[4];
    float d,e,f;
    
    for(int i=0;i<4;i++) {scanf("%d",&arr[i]);if(arr[i]==1) cnt ++;}
    switch (cnt)
    {
    case 1: printf("도");
        break;
    case 2: printf("개");
        break;
    case 3: printf("걸");
        break;
    case 4: printf("윷");
        break;
    case 0: printf("모");
        break;

    }

 
} 