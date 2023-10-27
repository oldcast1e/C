#include<stdio.h>
int main(){
    int ipt,val,cnt=2,num=-1,key=1,rep=0,fir,fir_cnt=0;
    scanf("%d",&ipt); val = ipt;
    while (val>0){
        if(val <= 1)break;
        if(val%cnt == 0){if(fir_cnt ==0 ){fir = cnt;fir_cnt++;}; rep++;if(num == cnt){printf("wrong number");key=0;break;}num = cnt;val= val/cnt;}
        else cnt++;
    } 
    if(rep==2 && key == 1)printf("%d %d",fir,ipt/fir);else if(key==1)printf("wrong number");
} 
