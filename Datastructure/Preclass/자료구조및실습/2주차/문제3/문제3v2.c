#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* prefixAverages1(int ar[],int n) {
	float sum = 0;
	int *p1 = (int *)malloc(sizeof(int)*n);
	if (p1 == NULL) return -1;
    /*------------*/
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < i + 1; j++) sum += ar[j];
		p1[i] = (int)((sum / (i + 1))+ 0.5)/1;
	}
	return p1;
}
int* pa2(int ar[], int n) {
	float sum = 0;
	int *p2 = (int *)malloc(sizeof(int)*n);
	if (p2 == NULL) return -1;
	
	for (int i = 0; i < n; i++) {
		
		sum += ar[i];
		//printf("sum = %f \n",sum);
		p2[i] = ((sum / (i + 1))+0.5)/1;
		
	}
	return p2;
}
int main(){
    int n,*x; scanf("%d",&n);
    x = (int*)malloc(sizeof(int)*n);

    int *rst1 = (int*)malloc(sizeof(int)*n);
    int *rst2 = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&x[i]);

    rst1 = prefixAverages1(x,n);
    rst2 = prefixAverages1(x,n);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);

    
    
} 
/*
원시 데이터값들로 구성된 배열 X의 i-번째 누적평균(prefix average)이란 
X의 i-번째에 이르기까지의 (i + 1)개 원소들의 평균이다. 
즉, A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)

3
5 1 9

6 
1 3 2 10 6 8
*/