#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}ListNode;


int main(){
    //순환문이용
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //엔드 노드 생성
    end = NULL;// end->next = end; 
    head->next = end; 

    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);

    /*이중동적*/
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)printf("%d ",dnum[i][j]);
    printf("\n"); cnt++;
    }

} 
/*
A : .-
B : -...
C : -.-.
D : -..
E : .
F : ..-.
G : --.
H : ....
I : ..
J : .---
K : -.-
L : .-..
M : --
N : -.
O : ---
P : .--.
Q : --.-
R : .-.
S : ...
T : -
U : ..-
V : ...-
W : .--
X : -..-
Y : -.--
Z : --..

{',', "--..--"}
{'.', ".-.-.-"}
{'?', "..--.."}
{';', "-.-.-."}
{':', "---..."}
{'/', "-..-."}
{'-', "-....-"}
{''', ".----."}
{'\"', ".-..-."}
{'_', "..--.-"}
{'(', "-.--."}
{')', "-.--.-"}
{'=', "-...-"}
{'+', ".-.-."}
{'@', ".--.-."}
{'!', "-.-.--"}
{'&', ".-..."}

*/