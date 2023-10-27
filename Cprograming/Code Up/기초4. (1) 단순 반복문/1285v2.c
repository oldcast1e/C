#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char arr[100],val;
    int cnt = 0,rst=0;
    while(1){
        scanf("%c",&arr[cnt]); if(arr[cnt]=='=') break;
        cnt ++;
    }
    for(int i=0;i<strlen(arr);i++){
        if(i==0) rst += arr[i]-'0';
        else{
            if(arr[i]=='+') {printf("%d + %d = %d\n",rst,(arr[i+1]-'0'),rst+(arr[i+1]-'0'));rst += (arr[i+1]-'0');}
            else if(arr[i]=='-') {printf("%d - %d = %d\n",rst,(arr[i+1]-'0'),rst-(arr[i+1]-'0'));rst -= (arr[i+1]-'0');}
            else if(arr[i]=='*') {printf("%d * %d = %d\n",rst,(arr[i+1]-'0'),rst*(arr[i+1]-'0'));rst *= (arr[i+1]-'0');}
            else if(arr[i]=='/') {printf("%d / %d = %d\n",rst,(arr[i+1]-'0'),rst/(arr[i+1]-'0'));rst /= (arr[i+1]-'0');}
        }
    }
    printf(">>%d",rst);
    // for(int i=0;i<strlen(arr);i++)printf("%c ",arr[i]);
 
} 
