#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num,rst = 0,cnt=1;
    char cal;

    // scanf("%d",&num); rst+=num; printf("rst = %d\n",rst);
    while(1){
        if(cnt%2!=0){
            scanf("%d",&num); if(cnt == 1)(rst  = num);
            if(cal == '+') rst += num;
            else if(cal == '-') rst -= num;
            else if(cal == '*') rst *= num;
            else if(cal == '/') rst /= num;
            cnt ++;
            
        }
        else if(cnt%2==0){
            scanf("%c",&cal); if(cal == '=')break;
            
            // if(cal == '+') rst += num;
            // else if(cal == '-') rst -= num;
            // else if(cal == '*') rst *= num;
            // else if(cal == '/') rst /= num;

            printf("rst = %d\n",rst);
            cnt++;
        }
    }printf("%d",rst);
} 
/*21


*/