#include <stdio.h>

int main()
{
   int n, now, bef = 0, max = 0;

   scanf("%d", &n);

   for (int i = 1; i <= n; i++) {
      scanf("%d", &now);
      if (max <= now) {
         bef = max;
         max = now;
      }
      
   }
   printf("%d\n", max);
   printf("%d", bef);

   return 0;
}

//10
//abc12defg2