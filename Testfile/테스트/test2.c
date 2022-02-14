#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
   for(int i=0;i<5;i++){
       for(int j=0;j<3;j++){
           if(i==j){
               printf("B!");
               break;
           }
           else printf("-");
       }
       
   }
}	
