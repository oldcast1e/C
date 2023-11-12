#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1,rev=0;
    int num[100];
    char arr[100];
    float n1,n2;
    //fgets(arr, 101, stdin);
    scanf("%d",&a);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=1;i<=a*a;i++){
        if(i>=a*a) break;
        else if(rev == 0 ){
            for(int j=i;j<i+a;j++){printf("%d ",j);}
            //1  ~ 1+3-1(3) , 현재 i = 1
            rev = 1;
            i += a -1;//1 + 3 = 4
            printf("\n");
        }
        else if(rev == 1){
            for(int j= i + a - 1;j >= i;j--){printf("%d ",j);}

            rev = 0;
            i += a-1;
            printf("\n");
        }
    }
    
} 
/*
1 2 3
6 5 4
7 8 9

1 2 3 4
8 7 6 5
9 10 11 12
*/