#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the middle of the list for partitioning
struct Node* findMiddle(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Partition function that divides the list into two halves
void partition(struct Node* head, struct Node** left, struct Node** right) {
    struct Node* middle = findMiddle(head);
    *left = head;
    *right = middle->next;
    middle->next = NULL;
}

// Merge two sorted linked lists
struct Node* merge(struct Node* L1, struct Node* L2) {
    if (!L1) return L2;
    if (!L2) return L1;

    struct Node* result = NULL;

    if (L1->data <= L2->data) {
        result = L1;
        result->next = merge(L1->next, L2);
    } else {
        result = L2;
        result->next = merge(L1, L2->next);
    }
    return result;
}

// Merge sort function for the linked list
struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL) return head;

    struct Node* left = NULL;
    struct Node* right = NULL;

    // Partition the list into two halves
    partition(head, &left, &right);

    // Recursively sort the two halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to insert a node at the end of the list
void append(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* last = *headRef;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct Node* list = NULL;

    // Inserting elements into the linked list
    append(&list, 5);
    append(&list, 2);
    append(&list, 9);
    append(&list, 1);
    append(&list, 6);

    printf("Original list:\n");
    printList(list);

    // Sorting the linked list
    list = mergeSort(list);

    printf("Sorted list:\n");
    printList(list);

    return 0;
}
