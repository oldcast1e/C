#include <stdio.h>
#include <stdlib.h>

/*
버전 4기준으로 버전 6추가

*/

// Structure to represent a term in a polynomial
typedef struct Node {
    int coef;  // Coefficient of the term
    int exp;  // Exponent of the term
    struct Node* next;  // Pointer to the next term
} Node;

// Function to create a new node
Node* getNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coef = 0;
    newNode->exp = 0;
    newNode->next = NULL;
    return newNode;
}

// Function to append a term to a polynomial
/*
다항식 k의 마지막 항
*/
void appendTerm(Node** result, int coef, int exp) {

    Node* curr = *result;
    Node* prev = NULL;
    //지수를 기준으로 삽입 위치 찾기
    while (curr && curr->exp > exp) {
        //NULL아닌 노드이고(&&) 노드의 차수가 입력받은 차수보다 큰 경우
        prev = curr;
        curr = curr->next;
    }
    
    if (curr && curr->exp == exp) {
        //지수가 같으면 계수를 더한다.
        curr->coef += coef;
        
        if (curr->coef == 0) { //계수가 0이면 노드를 추가하지 않는다.
            if (prev) prev->next = curr->next;
            else  *result = curr->next;
            free(curr);
        }
    }
    else {//지수가 같지 않은 경우 새 노드를 생성하고 올바른 위치에 삽입
        Node* newNode = getNode();
        newNode->coef = coef;
        newNode->exp = exp;
        if (prev) { //지수를 기준으로 찾은 삽입 위치가 NULL이 아닌경우(NULL 제외 모두 참)
            // (newNode->next) = (prev->next);
            // (prev->next )= newNode;
            (newNode->next) = (prev->next);
            (prev->next )= newNode;

        } 
        else {
            // newNode->next = *result;
            // *result = newNode;
            // (prev->next )= newNode;

        }
    }

    // Node* newNode = getNode();
    // newNode->coef = coef;
    // newNode->exp = exp;
    // temp->next = (*result)->next;
    // (*result)->next = temp;
}

// Function to add two polynomials
Node* addPoly(Node* x, Node* y) {
    Node* result = getNode();  // Create a new result polynomial

    Node* xlist = x->next;  //x의 첫 번째 항에 대한 포인터(헤더 건너뛰기)
    Node* ylist = y->next;  //y의 첫 번째 항에 대한 포인터(헤더 건너뛰기)
    Node* k = result;  //결과의 마지막 항에 대한 포인터(초기 결과)

    // 두 다항식 모두에 항이 있는 동안 두 다항식을 반복합니다.
    while (xlist && ylist) {
        if (xlist->exp > ylist->exp) {// x에서 더 높은 지수를 갖는 항을 추가합니다.
            appendTerm(&k, xlist->coef, xlist->exp);
            xlist = xlist->next;
        } 
        else if (xlist->exp < ylist->exp) {//더 낮은 지수를 사용하여 y에 항 추가
            appendTerm(&k, ylist->coef, ylist->exp);
            ylist = ylist->next;
        } 
        else {
            //항의 지수가 동일합니다. 계수를 추가하세요.
            // 합이 0이 아닌 경우에만 결합된 항을 추가합니다.
            if (xlist->coef + ylist->coef != 0) {appendTerm(&k, xlist->coef + ylist->coef, xlist->exp);}
            xlist = xlist->next;
            ylist = ylist->next;
        }
        k = k->next;  // Move k to the last term for the next iteration
    }

    // Append remaining terms from x (if any)
    while (xlist) {
        appendTerm(&k, xlist->coef, xlist->exp);
        xlist = xlist->next;
        k = k->next;
    }

    // Append remaining terms from y (if any)
    while (ylist) {
        appendTerm(&k, ylist->coef, ylist->exp);
        ylist = ylist->next;
        k = k->next;
    }

    return result;  // Return the resulting polynomial
}

// Function to print a polynomial (for testing purposes)
void printNode(Node* head) {
    Node* temp = head->next;
    while (temp) {
        printf("%d x^%d ", temp->coef, temp->exp);
        if (temp->next) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n,m,t_coe,t_exp;
    Node* xlist = getNode(); scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(&xlist,t_exp,t_coe);
    } 
    Node* ylist = getNode(); scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(&ylist,t_exp,t_coe);
    } 

    // Print the original polynomials
    printf("Polynomial x: ");printNode(xlist);
    printf("Polynomial y: ");printNode(ylist);

    // Add the polynomials
    Node* result = addPoly(xlist, ylist);

    // Print the resulting polynomial
    printf("Resultant polynomial: ");printNode(result);

    return 0;
}
/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0
*/