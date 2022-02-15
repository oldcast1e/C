// [변환 전](((A*B)+C)+((D+E)*F))
// (((A*B)+C)((D+E)*F))+
// (((A*B)C)+((D+E)*F))+
// (((A*B)C)+((D+E)F)*)+
// (((AB)*C)+((D+E)F)*)+
// (((AB)*C)+((DE)+F)*)+
// [변환 후]AB*C+DE+F*+

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


