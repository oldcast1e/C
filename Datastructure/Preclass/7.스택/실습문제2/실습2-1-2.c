#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node *pre;
}NODE;


NODE* createNode(char data){
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->pre = NULL;
	return temp;
}
char pop(NODE **top){
	NODE *temp = *top;
	char t;
	if(*top == NULL)
		return 0;
	*top = (*top)->pre;
	t = temp->data;
	free(temp);
	return t;
}

void push(NODE **top, char data){
	NODE *temp = createNode(data);
	if(*top == NULL){
		*top = temp;
		return;
	}
	temp->pre = *top;
	*top = temp;
}

void printCalc(NODE **top, char *input){
	for(int i = 0 ; i < strlen(input) ; i ++){
		switch(input[i]){
		case '*':
		case '-':
		case '/':
		case '+':
			push(top, input[i]);
			break;

		case ')':
			printf("%c", pop(top));
			break;

		case '(':
			break;

		default :
			printf("%c", input[i]);

		}
	}
}



int main(){

	NODE *TOP = NULL;
	char input[100];
	scanf("%s", input);
    for(int i)
	printCalc(&TOP, input);
	return 0;

}
/**
A/B-C+D*E-F*G
((((A/B)-C)+(D*E))-(F*G))
 */
