#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,k,cnt; 
    scanf("%d %d",&a,&k); cnt = k/2;//printf("초기 cnt값: %d\n",cnt);
    for(int i=0;i<a;i++){
        if(i==0 || i== (a-1)){for(int j=0;j<a;j++)printf("*");printf("\n");}
        else {
            printf("*");
            for(int j=1;j<a-1;j++){
                if(j%k==cnt || k==1)printf("*");
                else printf(" ");
            }
            // printf("*  >>cnt = %d\n",cnt);
            printf("*\n");
            if(cnt==0)cnt= k-1;
            else cnt--;
            // if(cnt == 1)cnt = 0;
            // else if(cnt == 0 )cnt = 2;
            // else if(cnt ==2)cnt = 1;
        }
    }
 
} 
/*
****| * |*****    [0]
**  | * |  * *    [1]
*  *|   | *  *    2
* * |   |*  **    3
**  | * |  * *    [4]
*  *|   | *  *    5
* * |   |*  **    6
**  | * |  * *    [7]
*  *|   | *  *    8
****| * |*****    [9]

**********
*1  4  7 *
*  3  6  *
* 2  5  8*
*1  4  7 *
*  3  6  *
* 2  5  8*
*1  4  7 *
*  3  6  *
********** 

**********
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
**********

**********
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
**********


10 -1
4-0
12-2
*/
