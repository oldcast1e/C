#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node {
    int coef;  // Coefficient of the term
    int exp;  // Exponent of the term
    struct Node* next;  // Pointer to the next term
} Node;

typedef struct list {
    //리스트의 정보 :  리스트의 헤드노드와 테일 노드의 설정 구조체
	int size;
	Node* head;
}list_info;

// Function to create a new node
Node* getNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = 0;
    newNode->exp = 0;
    newNode->next = NULL;
    return newNode;
}
void printNode(Node* head);
// Function to append a term to a polynomial
/*
다항식 k의 마지막 항

하나의 연결리스트의 각 노드는 차수의 내림차순 순으로 유지하고, 
계수가 0인 항의 노드는 유지하지 않음
*/

void appendTerm(Node** result, int coef, int exp) {
    
    if(coef!=0){
        Node* new = getNode();
        new->coef = coef;
        new->exp = exp;

        new->next = (*result)->next;
        (*result)->next = new;
    }
}

// Function to add two polynomials
Node* addPoly(Node* x, Node* y) {
    Node* result = getNode();  // Create a new result polynomial

    Node* xploy = x->next;   //x의 첫 번째 항에 대한 포인터(헤더 건너뛰기)
    Node* ypoly = y->next;   //y의 첫 번째 항에 대한 포인터(헤더 건너뛰기)
    Node* rst = result;  //결과의 마지막 항에 대한 포인터(초기 결과)

    while (xploy && ypoly) {
        // printf(">>");printNode(rst);
        if (xploy->exp > ypoly->exp) {// x에서 더 높은 지수를 갖는 항을 추가합니다.
            appendTerm(&rst, xploy->coef, xploy->exp);
            xploy = xploy->next;
        } 
        else if (xploy->exp < ypoly->exp) {//더 낮은 지수를 사용하여 y에 항 추가
            appendTerm(&rst, ypoly->coef, ypoly->exp);
            ypoly = ypoly->next;
        } 
        else {
            //항의 지수가 동일한 경우, 계수의 합을 가지는 항 추가
            if (xploy->coef + ypoly->coef != 0) {
                appendTerm(&rst, ((xploy->coef) + (ypoly->coef)), xploy->exp );}
                xploy = xploy->next;
                ypoly = ypoly->next;
        }
        rst = rst ->next;  // Move k to the last term for the next iteration
    }
    while(xploy){
        appendTerm(&rst, xploy->coef, xploy->exp);
        rst = rst ->next; 
        xploy = xploy->next;
    }
    while(ypoly){
        appendTerm(&rst, ypoly->coef, ypoly->exp);
        rst = rst ->next; 
        ypoly = ypoly->next;
    }

    return result;  // Return the resulting polynomial
}

// Function to print a polynomial (for testing purposes)
// void printNode(Node* head) {
//     Node* temp = head->next;
//     while (temp) {
//         printf("%d x^%d ", temp->coef, temp->exp);
//         if (temp->next) {
//             printf(" + ");
//         }
//         temp = temp->next;
//     }
//     printf("\n");
// }

void printNode(Node* head) {
    Node* temp = head->next;
    while (temp) {
        printf(" %d %d", temp->coef, temp->exp);
        temp = temp->next;
    }
}

int main() {
    int n,m,t_coe,t_exp,size = 0;
    Node* xlist = getNode(); 
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&t_exp,&t_coe); size ++;
    
        Node* prt = xlist; //순회용 노드 생성
        while(prt->next != NULL){
	        prt = prt->next;
        }
        appendTerm(&prt,t_exp,t_coe);
    } 

    Node* ylist = getNode(); 
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&t_exp,&t_coe); size ++;
    
        Node* prt = ylist; //순회용 노드 생성
        while(prt->next != NULL){
	        prt = prt->next;
        }
        appendTerm(&prt,t_exp,t_coe);
    }

    // printf("Polynomial x: ");printNode(xlist);
    // printf("Polynomial x: ");printNode(ylist);

    Node* result = addPoly(xlist, ylist);
    // printf("Resultant polynomial: ");
    printNode(result);
    return 0;
}
/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0

2
2 7 3 0
3
-3 10 3 7 -3 0
*/