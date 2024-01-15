#include <stdio.h>
int main() {int a[10001],n,i,j,temp,key=1,rst=0;scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",&a[i]);
for(i=1; i<n;i++){key =1;for(j=1;j<=n-i;j++){if(a[j]>a[j+1]){temp=a[j];a[j]=a[j+1];a[j+1]=temp;}}
for(j=n-i;j>=2;j--)if(a[j]<a[j-1]){key=0;break;}if(key==1){rst=i;break;}}
rst=rst==0?1:rst;printf("%d",rst);}
