#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct A{
    int data;
    char name;
}AA;

// struct B{
//     int data;
//     char name[10];
// }BB;
int main(void){
   struct A *stra = &AA;
   struct A *strb ;
   stra->name = 'S';
   stra->data = 1;

   strb = stra;

   strb->data = 3;
   printf(">%d",stra->data);


    
   
}