#include <stdio.h>
#include <stdlib.h>

void selectSort(int n);
void insertSort(int n);

int *ar;

int main(){
	int n;
	scanf("%d", &n);
	ar = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {scanf("%d", &ar[i]);}
	insertSort(n);
	
	for (int i = 0; i < n; i++)printf("%d ", ar[i]);
}

void selectSort(int n) {
	for (int j = n-1; j >= 0; j--){
		int max_idx = j;
		for (int i = 0; i < j; i++) {
			if (ar[i] > ar[max_idx]) max_idx = i;
		}
		int tmp = ar[j];
		ar[j] = ar[max_idx];
		ar[max_idx] = tmp;
	}
}

void insertSort(int n) {
	int save;
	int j ;
	for (int i = 1; i < n; i++) {
		save = ar[i];
		 j = i - 1;
		while ((j >= 0) && (ar[j] > save)){
			ar[j+1] = ar[j];	
			j--;
		}
		ar[j + 1]=save;
	}
}

void insert(int n) {
	for (int i = 1; i < n; i++) {
		int save = ar[i];
		int j = i - 1;
		while ((j >= 0) && (ar[j] > save)) {
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j + 1] = save;
	}
}