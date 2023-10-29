#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num,i=0,pre,max = 0;
    char key = '_',chc;
    
    while(1){
        if(i%2==0){
            scanf("%d",&num);
            if(key == '_')pre = num;
            
            if(key == '+'){num = pre + num; pre =  num; }
            else if(key == '-'){num = pre - num; pre =  num; }
            else if(key == '*'){num = pre * num; pre =  num; }
            else if(key == '/'){num = pre / num; pre =  num; }

        }
        else if(i%2!=0){scanf("%c",&chc); if(chc == '=') break;key = chc;}
        i++;
    }printf("%d",num);
 
} 
