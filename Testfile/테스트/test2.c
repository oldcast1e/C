#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct A{
    int data;
    char name;
}AA;

int main(void){
   struct A *stra = &AA;
   struct A *strb ;

   stra->name = 'A';
   stra->data = 1;

   strb = stra;

   strb->data = 10;
   printf(">%d",stra->data);


}