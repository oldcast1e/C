#include <stdio.h>
#include <stdlib.h>

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

// Function to append a term to a polynomial in descending order of exponent
void appendTerm(Node** result, int coef, int exp) {
    Node* temp = *result;
    Node* prev = NULL;


    //지수를 기준으로 삽입 위치 찾기
    while (temp && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    //지수가 같으면 계수를 더한다.
    if (temp && temp->exp == exp) {
        temp->coef += coef;
        // Do not add a node if the coefficient is 0
        if (temp->coef == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                *result = temp->next;
            }
            free(temp);
        }
    } else {
        // Create a new node and insert it in the correct position
        Node* newNode = getNode();
        newNode->coef = coef;
        newNode->exp = exp;
        if (prev) {
            newNode->next = prev->next;
            prev->next = newNode;
        } else {
            newNode->next = *result;
            *result = newNode;
        }
    }
}

// Function to add two polynomials
Node* addPoly(Node* x, Node* y) {
    Node* result = getNode();  // Create a new result polynomial

    Node* xlist = x->next;  //x의 첫 번째 항에 대한 포인터(헤더 건너뛰기)
    Node* ylist = y->next;  //y의 첫 번째 항에 대한 포인터(헤더 건너뛰기)

    // Iterate through both polynomials
    while (xlist || ylist) {
        if (xlist && ylist) {
            if (xlist->exp  >  ylist->exp) {
                appendTerm(&result, xlist->coef, xlist->exp);
                xlist = xlist->next;
            } else if (xlist->exp < ylist->exp) {
                appendTerm(&result, ylist->coef, ylist->exp);
                ylist = ylist->next;
            } else {
                // Terms have the same exponent, add coefficients
                int sum = xlist->coef + ylist->coef;
                if (sum != 0) {
                    appendTerm(&result, sum, xlist->exp);
                }
                xlist = xlist->next;
                ylist = ylist->next;
            }
        } else if (xlist) {
            appendTerm(&result, xlist->coef, xlist->exp);
            ylist = ylist->next;
        } else if (ylist) {
            appendTerm(&result, ylist->coef, ylist->exp);
            ylist = ylist->next;
        }
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

Polynomial x: 3 x^2  + 3 x^1  + 0 x^0 
Polynomial y: 2 x^3  + 1 x^0 
Resultant polynomial: 3 x^2  + 3 x^1  + 1 x^0 
*/