#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move the fast pointer to the end of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the list has an even number of elements, return the second middle element
    if (fast != NULL) {
        return slow->next;
    }

    // Otherwise, return the middle element
    return slow;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->next->data = 5;

    Node* middle = findMiddle(head);
    printf("The middle element is %d\n", middle->data);

    return 0;
}