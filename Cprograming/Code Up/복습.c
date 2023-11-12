#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num,rst = 0,cnt=1;
    char cal;

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
            // printf("rst = %d\n",rst);
            cnt++;
        }
    }printf("%d",rst);
} 
/*21


*/