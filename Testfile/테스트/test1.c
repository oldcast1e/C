#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int x, y, z,tmp, *px = &x, *py = &y, *pz = &z,*ptmp = &tmp;

    scanf("%d",px);
    scanf("%d",py);
    scanf("%d",pz);

    // *tmp = *py;
    // *py = *px;
    // *px = *pz;
    // *pz = *tmp;

    *ptmp = *px;
    *px = *py;
    *py = *pz;
    *pz = *ptmp;

    printf("%d %d %d\n", *px, *py, *pz);
}