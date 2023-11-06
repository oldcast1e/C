#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int num[1000];


    //fgets(arr, 101, stdin);
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",&num[i]);

    for(int i=0;i<a;i++){
        printf("%d: ",i+1);
        for(int j=0;j<a;j++){
            if(i!=j){
                if(num[i]>num[j])printf("> ");
                else if(num[i]==num[j])printf("= ");
                else if(num[i]<num[j])printf("< ");
            }
        }printf("\n");
    }

} 
/*

*/