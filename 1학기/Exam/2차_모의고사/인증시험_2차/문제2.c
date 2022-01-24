#include <stdio.h>
int main()
{
   char u;
   char rst[100],inp[100]; 
   int cnt = 0;
   int r= 0;
   int k =0,max=-1;

   while(1){

       scanf("%c",&u);
       if(u=='*') break;
       inp[r] = u;
       if('A'<=u && u<='Z'){
           rst[cnt] = u+ 32;
           cnt ++;
       }
       if('a'<=u && u<='z'){
           rst[cnt] = u- 32;
           cnt ++;
       }
       r++;
       
   }
    k = 0;
   for(int i=0;i<r;i++){
       k=0;
       if(inp[i]!='A'&& inp[i]!='E'&&inp[i]!='I'&&inp[i]!='O'&&inp[i]!='U'){
           if(inp[i+1]=='a'||inp[i+1]=='e'||inp[i+1]=='i'||inp[i+1]=='o'||inp[i+1]=='u'){
                if(inp[i+2]!='a'&& inp[i+2]!='e'&&inp[i+2]!='i'&&inp[i+2]!='o'&&inp[i+2]!='u'){
                    k++;
                }
            }
       }
       if(k>max) max = k;

   }
   for(int i=0;i<cnt;i++){
       printf("%c",rst[i]);
   }
   printf("\n");
   printf("%d",max);
   

}