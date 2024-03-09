#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int* pa1(int ar[],int n) {
	float sum = 0;
	int *p1 = (int *)malloc(sizeof(int)*n);
	// if (p1 == NULL) return -1;

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i + 1; j++) {
			sum += ar[j];
		}
		
		p1[i] = (int)((sum / (i + 1))+ 0.5)/1;
	}
	return p1;
}

int* pa2(int ar[], int n) {
	float sum = 0;
	int *p2 = (int *)malloc(sizeof(int)*n);
	// if (p2 == NULL) return -1;
	
	for (int i = 0; i < n; i++) {
		
		sum += ar[i];
		//printf("sum = %f \n",sum);
		p2[i] = ((sum / (i + 1))+0.5)/1;
		
	}
	return p2;
}

int main()
{
	int n;
	scanf("%d", &n);
	int* ar;
	int * p2;
	int * p1;
	ar = (int *)malloc(sizeof(int)*n);


	if (ar == NULL) return -1;


	for (int i = 0; i < n; i++) {
		scanf("%d", &ar[i]);
	}
	p1 = pa1(ar, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", p1[i]);
	}
	
	printf("\n");
	p2 = pa2(ar, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", p2[i]);
	}

	
	return 0;
}

