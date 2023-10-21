#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;scanf("%d %d %d",&a,&b,&c);
    printf("%d",a<b?(a<c)?a:c:(b<c?b:c));
    // printf("%d",a<b?(a<c?a:(b<a?(b<c?b:c):c)):c);
}
//3 -1 5-