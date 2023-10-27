#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int cnt=0,rst=0,pre;
    float n1,n2;
    char c;
    while(1){
        scanf("%c",&c); if(c=='=') break;
        if(cnt==0){cnt=1;pre = c-'0';}
        else if(cnt!=0){
            if('0'<=c && c<='9'){pre = c-'0';printf(">>pre = %d\n",pre); }
            else{// printf("====> \n");
                switch(c){
                    case '+': 
                        // printf("%d + %d = %d\n",rst,pre,rst+pre);
                        rst = rst + pre; 
                        break;
                        
                    case '-': 
                        // printf("%d - %d = %d\n",rst,pre,rst-pre);
                        rst = rst - pre; 
                        break;

                    case '*': 
                        // printf("%d * %d = %d\n",rst,pre,rst*pre);
                        rst = rst * pre; 
                        break;

                    case '/': 
                        // printf("%d / %d = %d\n",rst,pre,rst/pre);
                        rst = rst / pre; 
                        break;
                }
            }
        }
        
    }printf("%d",rst);
 
} 

/*

pre = [3] rst = [3]
pre = [3] rst = [0]
pre = [3] rst = [0]
pre = [3]
rst = [0]
pre = [3]
*/
