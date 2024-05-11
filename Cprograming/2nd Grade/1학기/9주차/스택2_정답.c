#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

char* push(char* sta, char data) {
	int k = strlen(sta);
	if (k == 0) {
		*sta = data;
		*(sta + 1) = NULL;
	}
	else {
		for (int i = 0; i < k ; i++){
			*(sta + k - i) = *(sta + k - i-1);
		}
		*sta = data;
		*(sta + k+1) = NULL;
	}
	//printf("push %s\n", sta);
	return sta;
}

char* pop(char* sta) {
	int k = strlen(sta);
	for (int i = 0; i < strlen(sta); i++) {
		sta[i] = sta[i+1];
	}
	sta[k-1] = NULL;
	return sta;
}

char peek(char* sta) {
	return sta[0];
}

void print(char* sta) {
	printf("%s", sta);
	printf("\n");
}

int main(){
	char str[1001];
	fgets(str,1001,stdin);
	char* sta = (char*)malloc(sizeof(char) * 1000);
	sta[0] = NULL;
	int cnt = 0;
	int res = 0;
	int len = strlen(str);
	
	for (int i = 0;; i++) {
		if (*(str+i) == NULL) break;
		if ((str[i] == '(')|| (str[i] == '{')|| (str[i] == '[')) {
			sta = push(sta, str[i]);
			cnt++;
			//printf("%c %d\n", str[i], cnt);
			//print(sta);
		}
		else if (str[i] == ')') {
			if ('(' == sta[0]) sta=pop(sta);
			else res = 1;
			//printf("%c %d\n", str[i], cnt);	
			cnt++;
		}
		else if (str[i] == '}') {
			if ('{' == sta[0]) sta = pop(sta);
			else res = 1;
			//printf("%c %d\n", str[i], cnt);	
			cnt++;
		}
		else if (str[i] == ']') {
			if ('[' == sta[0]) sta = pop(sta);
			else res = 1;
		//printf("%c %d\n", str[i], cnt);	
			cnt++;
		}
	}

	if ((res == 1)||(strlen(sta)!=0)) {
		printf("Wrong_%d", cnt);
	}
	else printf("OK_%d", cnt);


	return 0;
}
