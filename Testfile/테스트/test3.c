#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node {
    int coef;  // Coefficient of the term
    int exp;  // Exponent of the term
    struct Node* next;  // Pointer to the next term
} Node;

// Function to create a new node
Node* getnode() {
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

    // Find the insertion position based on exponent
    while (temp && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    // If the exponent is the same, add coefficients
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
        Node* newNode = getnode();
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
    Node* result = getnode();  // Create a new result polynomial

    Node* i = x->next;  // Pointer to the first term of x (skip the header)
    Node* j = y->next;  // Pointer to the first term of y (skip the header)

    // Iterate through both polynomials
    while (i || j) {
        if (i && j) {
            if (i->exp > j->exp) {
                appendTerm(&result, i->coef, i->exp);
                i = i->next;
            } else if (i->exp < j->exp) {
                appendTerm(&result, j->coef, j->exp);
                j = j->next;
            } else {
                // Terms have the same exponent, add coefficients
                int sum = i->coef + j->coef;
                if (sum != 0) {
                    appendTerm(&result, sum, i->exp);
                }
                i = i->next;
                j = j->next;
            }
        } else if (i) {
            appendTerm(&result, i->coef, i->exp);
            i = i->next;
        } else if (j) {
            appendTerm(&result, j->coef, j->exp);
            j = j->next;
        }
    }

    return result;  // Return the resulting polynomial
}

// Function to print a polynomial (for testing purposes)
void printPoly(Node* head) {
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
    Node* xlist = getnode(); scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(&xlist,t_exp,t_coe);
    } 
    Node* ylist = getnode(); scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&t_exp,&t_coe);
		appendTerm(&ylist,t_exp,t_coe);
    } 

    // Print the original polynomials
    printf("Polynomial x: ");printPoly(xlist);
    printf("Polynomial y: ");printPoly(ylist);

    // Add the polynomials
    Node* result = addPoly(xlist, ylist);

    // Print the resulting polynomial
    printf("Resultant polynomial: ");printPoly(result);

    return 0;
}