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

// Function to append a term to a polynomial
/*
다항식 k의 마지막 항
*/
void appendTerm(Node** result, int coef, int exp) {
    Node* temp = getNode();
    temp->coef = coef;
    temp->exp = exp;
    temp->next = (*result)->next;
    (*result)->next = temp;
}

// Function to add two polynomials
Node* addPoly(Node* x, Node* y) {
    Node* result = getNode();  // Create a new result polynomial

    Node* i = x->next;  // Pointer to the first term of x (skip the header)
    Node* j = y->next;  // Pointer to the first term of y (skip the header)
    Node* k = result;  // Pointer to the last term of the result (initially result)

    // Iterate through both polynomials while there are terms in both
    while (i && j) {
        if (i->exp > j->exp) {
            // Append term from x with higher exponent
            appendTerm(&k, i->coef, i->exp);
            i = i->next;
        } else if (i->exp < j->exp) {
            // Append term from y with lower exponent
            appendTerm(&k, j->coef, j->exp);
            j = j->next;
        } else {
            // Terms have the same exponent, add coefficients
            int sum = i->coef + j->coef;
            if (sum != 0) {
                // Append the combined term only if the sum is non-zero
                appendTerm(&k, sum, i->exp);
            }
            i = i->next;
            j = j->next;
        }
        k = k->next;  // Move k to the last term for the next iteration
    }

    // Append remaining terms from x (if any)
    while (i) {
        appendTerm(&k, i->coef, i->exp);
        i = i->next;
        k = k->next;
    }

    // Append remaining terms from y (if any)
    while (j) {
        appendTerm(&k, j->coef, j->exp);
        j = j->next;
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