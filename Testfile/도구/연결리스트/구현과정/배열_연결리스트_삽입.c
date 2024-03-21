#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ipt,Data[5]={'A','B','D','E'};
char c;

int main(){
    int i,temp,temp2;
    c = 'C';
    for(i=0;i<5;i++) printf("%2c",Data[i]); printf("\n");
    for(i=0;i<5;i++)
        if(Data[i]>c) break;
    
    temp = Data[i]; Data[i] = c; i++;

    for(;i<5;i++){
        temp2 = Data[i];
        Data[i] = temp;
        temp = temp2;
    }
    for(int i=0;i<5;i++)printf("%c ",Data[i]);
}