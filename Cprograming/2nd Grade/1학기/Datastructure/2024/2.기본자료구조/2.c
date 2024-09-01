#include <stdio.h>
#include <stdlib.h>
int main()
{
	int len = 4;
	int* arr = (int*)calloc(len,sizeof(int));
	for (int i = 0; i < len; i++)printf("%d",arr[i]);
}