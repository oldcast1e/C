#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct gas{
    int num;
    int pos;
};

void swap(int *n,int *m){
    int tmp = *n; *n= *m; *m= tmp;
}

int main(){
    int n;scanf("%d",&n);
    struct gas myGas[n];
    for(int i=0;i<n;i++)scanf("%d %d",&myGas[i].num,&myGas[i].pos);

    for(int i=0;i<n;i++){
        for(int k=0;k<n-i-1;k++){
            if (myGas[k].num > myGas[k+1].num)
            {
                // printf(">ch");
                swap(&myGas[k].pos,&myGas[k+1].pos);
                swap(&myGas[k].num,&myGas[k+1].num);
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d %d\n",myGas[i].num,myGas[i].pos);
} 
/*

*/