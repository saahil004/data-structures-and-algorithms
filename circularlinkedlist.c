#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head) {
    struct Node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

struct Node* insertAtBeginning(int data ,struct Node *head) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    new->data = data;
    if (head == NULL) {
        new->next = new;  // Point to itself
        return new;
    }
    new->next = ptr;
    // head = new;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return new;
}

void insertAtEnd(int data, struct Node *head) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    new->data = data;
    while (ptr->next != head) 
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

int main() {
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = first;
    //initializing data and linking them
    first->data = 11;
    second->data = 144;
    third->data = 14;
    first->next = second;
    second->next = third;
    third->next = head;
    int choice = 0;
    int val;
    while (choice != 4)
    {
         printf("Enter 1 to display the circular linked list.\nEnter 2 to add a node in the beginning.\nEnter 3 to insert at the end.\nEnter 4 to exit.\nChoice: ");
         scanf("%d", &choice);
         switch (choice)
         {
         case 1:
            Traversal(head);
            break;
         case 2:
            printf("Enter the value to be inserted in the beginning: ");
            scanf("%d", &val);
            head = insertAtBeginning(val, head);
            break;
         case 3:
            printf("Enter the value to be inserted in the end: ");
            scanf("%d", &val);
            insertAtEnd(val, head);
            break; 
         default:
            break;
         }
    }
    
    return 0;
}