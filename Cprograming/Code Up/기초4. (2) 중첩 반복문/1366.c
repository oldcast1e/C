#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt=1;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        if(i==0 || i== (a-1) || i == a/2){for(int j=0;j<a;j++)printf("*");printf("\n");if(i == a/2)cnt++;}
        else {
            printf("*");
            for(int j=1;j<a-1;j++){
                if(j==cnt || j==((a-1)-cnt))printf("*");
                else if(j==(a)/2)printf("*");
                else printf(" ");
            }cnt++;
            printf("*\n");
        }
    }
 
} 
/*
*****************
**      *      **
* *     *     * *
*  *    *    *  *
*   *   *   *   *
*    *  *  *    *
*     * * *     *
*      ***      *
*****************
*      ***      *
*     * * *     *
*    *  *  *    *
*   *   *   *   *
*  *    *    *  *
* *     *     * *
**      *      **
*****************

*****************
**      *      **
* *     *     * *
*  *    *    *  *
*   *   *   *   *
*    *  *  *    *
*     * * *     *
*      ***      *
*****************
*       *       *
*      ***      *
*     * * *     *
*    *  *  *    *
*   *   *   *   *
*  *    *    *  *
* *     *     * *
*****************
*/