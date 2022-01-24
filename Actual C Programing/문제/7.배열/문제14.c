#include <stdio.h>

int main(void)
{
 int i, key, k,n=1;  // key * key = n; 
 int H=0, W=0, Fn;
 int arr[50][50] = {0,};
 scanf("%d", &key);
 k=key;
 
 while(key != 0)
 {
  Fn=n;  // 세로 시작 숫자  
  
  if(Fn%2 != 0)
  {
   for(i=0 ;i<key ; i++)
   arr[H][W++] = n++;
   W-=1;
   H+=1;
   key--;
   
   for(i=0 ; i<key ; i++)
   arr[H++][W] = n++;
   H-=1;
   W-=1;
  }


  else
  {
   for(i=0 ;i<key ; i++)
   arr[H][W--] = n++;
   W+=1;
   H-=1;
   key--;
   
   for(i=0 ; i<key ; i++)
   arr[H--][W] = n++;
   H+=1;
   W+=1;
  }
 }
 
 
 for(i=0 ; i<k ;i++)
 { 
  for(int j=0 ; j<k ; j++)
  printf("%3d", arr[i][j]);
  printf("\n");
 }
}  
