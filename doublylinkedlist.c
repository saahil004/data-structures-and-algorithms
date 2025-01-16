#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void Traversal(struct Node *head) {
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node* reverse(struct Node *head) {
    struct Node *ptr = head;
    struct Node *temp;
    while (ptr->next != NULL)
    {
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = ptr->prev;
    }
    temp = ptr->next;
    ptr->next = ptr->prev;
    ptr->prev = temp;
    return ptr;
}

int main() {
    struct Node *n1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = n1;
    n1->data = 23;
    n2->data = 34;
    n3->data = 56;
    n4->data = 52;
    n1->prev = NULL;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = NULL;
    Traversal(head);
    head = reverse(head);
    Traversal(head);
    return 0;
}