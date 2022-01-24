#include  <stdio.h>
int main(){
    
    int num = 3,*pnum = &num,**ppnum = &pnum;

    printf("%p %d\n",&num,num);
    printf("%p %p %d\n",&pnum,pnum,*pnum);
    printf("%p %p %d",&ppnum,ppnum,**ppnum);

}

