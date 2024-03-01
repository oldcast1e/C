#include <stdio.h>
#include <stdlib.h>
int main()
{   
    //malloc
    int len = 4;
    int * arr = (int *)malloc(sizeof(int) * len);
    for(int i = 0; i < len; i++) *(arr + i) = i;
    for(int i = 0; i < len; i++)printf("%d",arr[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int len = 4;
	int* arr = (int*)calloc(len,sizeof(int));
	for (int i = 0; i < len; i++)printf("%d",arr[i]);
}
*/