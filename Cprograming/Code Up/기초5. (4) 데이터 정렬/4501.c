#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num[7],fir_max = -1,sec_max = -1,idx;
    for(int i=0;i<7;i++) scanf("%d",&num[i]);
    
    for(int i=0;i<7;i++){
        if(fir_max < num[i]) {fir_max = num[i];idx = i;}
    }
    printf("%d\n",fir_max); num[idx] = 0;

    for(int i=0;i<7;i++){
        if(sec_max < num[i]) {sec_max = num[i];idx = i;}
    }
    printf("%d\n",sec_max); //num[idx] = 0;
    
} 
/*

*/