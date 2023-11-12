#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int cnt1=0,cnt2=0,key=0;
    int num_1[100],num_2[100];
    char arr[100],cal;
    float n1=0,n2=0,rst;
    //fgets(arr, 101, stdin);
    // scanf("%d",num);
    scanf("%s",arr);
    for(int i=0;i<(int)strlen(arr);i++){
        if(key == 0 && ('0' <= arr[i] && arr[i] <= '9')){
            num_1[cnt1] = arr[i] -'0';
            cnt1 ++;
        }
        if(arr[i] == '+' || arr[i]=='-'){
            cal = arr[i];
            key = 1;
        }
        if(key == 1 &&( '0' <= arr[i] && arr[i] <= '9')){
            num_2[cnt2] = arr[i] -'0';
            cnt2 ++;
        }
    }

    for(int i=0;i<cnt1;i++){
        n1 += num_1[i];
        n1*=10;
    }n1/=10;
    
    for(int i=0;i<cnt2;i++){
        n2 += num_2[i];
        n2*=10;
    }n2/=10;

    // scanf("%d %d %d %d",&a,&b,&c,&d);
    if(cal == '+')printf("-");
    rst = n2/n1;
    printf("%.2f",rst);
    // printf("%.2f %.2f",n1,n2);
    
} 
/*
5x+4
x의 값을 반올림하여 소숫점 둘째 자리까지 출력한다.
*/