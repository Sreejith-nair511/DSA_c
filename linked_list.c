#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node in the linked list
struct Node {
    int data;
    struct Node* next;
};//this is our structure 

// Function to insert a new node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list using Bubble Sort
void sortList(struct Node* head) {
    struct Node* i;
    struct Node* j;
    int temp;
//this is the general bubble logic 
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //this will reverse the list 
    *head = prev;
}

// Function to insert an element in the sorted list
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    //dma function to extends and allocate memeory 
    struct Node* curr = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
        //or operator usage 
    }

    while (curr->next != NULL && curr->next->data < data) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    struct Node* head = NULL;
 //our main fucntion 
    insertEnd(&head, 3);
    insertEnd(&head, 1);
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 5);

    printf("Original List: \n");
    printList(head);

    sortList(head);
    printf("\nSorted List: \n");
    printList(head);

    reverseList(&head);
    printf("\nReversed Sorted List: \n");
    printList(head);

    insertSorted(&head, 3);
    printf("\nList after Insertion: \n");
    printList(head);

    return 0;
}
