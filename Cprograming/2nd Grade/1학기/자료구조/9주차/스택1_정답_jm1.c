#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef char element;

char* push(char* stack, char data) {
	int k = strlen(stack);
	if (k == 0) {
		*stack = data;
		*(stack + 1) = NULL;
	}
	else {
		for (int i = 0; i < k ; i++) {
			*(stack + k - i) = *(stack + k - i-1);
		}
		*stack = data;
		*(stack + k+1) = NULL;
	}
	//printf("push %s\n", stack);
	return stack;
}

char* pop(char* stack) {
	int k = strlen(stack);
	for (int i = 0; i < strlen(stack); i++) {
		stack[i] = stack[i+1];
	}
	stack[k-1] = NULL;
	return stack;
}

char* duplicate(char* stack) {
	int k = strlen(stack);
	for (int i = 0; i < k; i++) {
		*(stack + k - i) = *(stack + k - i - 1);
	}
	*stack = stack[0];
	*(stack + k + 1) = NULL;
	//printf("dup=%s\n", stack);
	return stack;
}

void peek(char* stack) {
	printf("%c\n",stack[0]);
}

char* upRotate(char* stack, int n) {
	int k = strlen(stack);
	char data = stack[0];
	for (int i = 0; i < n-1; i++) {
		*(stack + i) = *(stack + i +1);
	}
	stack[n-1]=data;
	
	//printf("upR=%s\n", stack);
	return stack;
}

char* downRotate(char* stack, int n) {
	int k = strlen(stack);
	char data = stack[n-1];
	for (int i = 0; i < n - 1; i++) {
		*(stack + n-1-i) = *(stack +n-i-2);
	}
	stack[0] = data;

	//printf("upR=%s\n", stack);
	return stack;
}

void print(char* stack) {
	printf("%s", stack);printf("\n");
}

int main(){
	int n,time;
	scanf("%d",&n);getchar();
	char* stack;
	stack = (char*)malloc(sizeof(char)*(n+1)); stack[0] = NULL;
	
    scanf("%d", &time);getchar();
	
    for (int i = 0; i < time; i++) {
		//printf("time = %d\n", i);
		char func[6];
		scanf("%s", func);

		if (strcmp(func, "POP") == 0) {
			getchar();
			if (strlen(stack) == 0) printf("Stack Empty\n");
			else stack = pop(stack);
		}
		else if (strcmp(func, "PUSH") == 0) {
			if (strlen(stack) < n) {
				getchar();
				char data;
				scanf("%c", &data);
				getchar();
				stack = push(stack, data);
			}
			else {
				getchar();
				printf("Stack FULL\n");
				getchar();
			}
		}
		else if (strcmp(func, "PEEK") == 0) {
			getchar();
			if (strlen(stack) == 0) printf("Stack Empty\n");
			else peek(stack);
		}
		
		else if (strcmp(func, "DUP") == 0) {
			getchar();
			if (strlen(stack) >=n) printf("Stack Empty\n");
			else stack = duplicate(stack);
		}
		else if (strcmp(func, "UpR") == 0) {
			int rank;scanf("%d", &rank); getchar();
			//printf("rank=%d\n", rank);
			
			if (strlen(stack) >= rank) stack = upRotate(stack, rank);
		}
		else if (strcmp(func, "DownR") == 0) {
			int rank;
			scanf("%d", &rank);getchar();
			if (strlen(stack) >= rank) downRotate(stack, rank);
		}else if (strcmp(func, "PRINT") == 0) {
			getchar();
			print(stack);
		}
		else {

		}
		
	}



	return 0;
}
