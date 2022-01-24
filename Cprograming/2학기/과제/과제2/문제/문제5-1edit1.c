#include <stdio.h>
#include<string.h>
typedef struct {
	char string[51];
	int length;
}array;
array sort[20001];

void merge_sort(int left, int right, array *input);
void merge(int left, int right, int mid, array *input);

int main(void) {
	
	int N,cnt=0;
	
	scanf("%d", &N);
	
	array input[N];
	
	int i, j;
	for(i = 0;; i++){
		memset(input[i].string, 0, 51);
		scanf("%s", input[i].string);
		
		for(j = 0; j< 51; j++){
			if(input[i].string[j] == 0){
				input[i].length = j;
				break;
			}
		}
	}
	
	merge_sort(0, N-1, input);
	
	for(i = 0; i < N; i++){
		if(i == 0)
			printf("%s\n", input[i].string);
		else{
			if(strcmp(input[i-1].string, input[i].string) != 0){
				 printf("%s\n", input[i].string);
			}	
		}
	}
	return 0;
}

void merge_sort(int left, int right, array *input){
	int mid = (left + right) / 2;
	
	if(left < right){
		merge_sort(left, mid, input);
		merge_sort(mid + 1, right, input);
		merge(left, right, mid, input);
	}
	
}
void merge(int left, int right, int mid, array *input){
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	
	while(i <= mid && j <= right){
		if(input[i].length < input[j].length){
			sort[k++] = input[i++];
		}else if(input[i].length == input[j].length){
			if(strcmp(input[i].string, input[j].string) < 0){
				sort[k++] = input[i++];
			}else{
				sort[k++] = input[j++];
			}
		}else{
			sort[k++] = input[j++];
		}
	}
	
	if(i <= mid){
		while(i <= mid){
			sort[k++] = input[i++];
		}	
	}else{
        while(j <= right){
			sort[k++] = input[j++];
		}
	}
	
	for(k = left; k <= right; k++){
		input[k] = sort[k];
	}
}
