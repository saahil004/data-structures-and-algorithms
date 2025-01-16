#include <stdio.h>
#include <stdlib.h>


//singly linkedlist
struct Node
{
    int data;
    struct Node *next;
};


//traversal
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

void deleteList(struct Node *head) {
     struct Node *ptr = head;
     struct Node *next;
     while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
     }
}


//insertion cases
struct Node* insertAtBeginning(int data, struct Node *head) {
      struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
      newNode->next = head;
      newNode->data = data;
    //   head = newNode;  
      return newNode;
}

void insertAtIndex(int data, int index, struct Node *head) {
      struct Node *new = (struct Node *)malloc(sizeof(struct Node));
      struct Node *ptr = head;
      int i = 0;
      while (i != index - 1 && index > 0)
      {
        ptr = ptr->next;
        i++;
      }
      new->data = data;
      new->next = ptr->next;
      ptr->next = new;
}


void insertAtEnd(int data, struct Node *head) {
      struct Node *new = (struct Node *)malloc(sizeof(struct Node));
      struct Node *ptr = head;
      while (ptr->next != NULL)
      {
        ptr = ptr->next;
      }
      new->data = data;
      ptr->next = new;
      new->next = NULL;
}

void insertAfterNode(int data, struct Node *prev) {
      struct Node *new = (struct Node *)malloc(sizeof(struct Node));
      new->data = data;
      new->next = prev->next;
      prev->next = new;
}

void insertAfterVal(int data, int val, struct Node *head) {
      struct Node *new = (struct Node *)malloc(sizeof(struct Node));
      struct Node *ptr = head;
      new->data = data;
      ptr = head;
      while (ptr->data != val && ptr != NULL)
      {
        ptr = ptr->next;
      }
      if (ptr == NULL) {
        return;
      } else {
        new->next = ptr->next;
        ptr->next = new;
      }
      
}

//deletion cases
struct Node* deleteFirstNode(struct Node *head) {
      struct Node *ptr = head;
      head = head->next;
      free(ptr);
      return head;
}

void deleteInBetween(int ind, struct Node *head) {
      struct Node *ptr = head;
      int i = 0;
      while (i < ind - 1 && ptr != NULL) 
      {
        ptr = ptr->next;
        i++;
      }
      struct Node *q = ptr;
      q = q->next;
      ptr->next = q->next;
      free(q);
      
}

void deleteLastNode(struct Node *head) {
  struct Node *prev = head;
  struct Node *ptr = head->next;
  while (ptr->next != NULL && ptr != NULL)
  {
       ptr = ptr->next;
       prev = prev->next;
  }
  if (ptr == NULL)
  {
    deleteFirstNode(head);
  }
  
  free(ptr);
  prev->next = NULL;
}

struct Node* deleteNodeUsingVal(int val, struct Node *head) {
    int i = 0;
    struct Node *p = head;
    struct Node *q = head->next;
    if (p->data == val) {
      head = deleteFirstNode(head);
      return head;
    }
    while (q->data != val) 
    {
      p = p->next;
      q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main() {
    //three nodes
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
    third->next = NULL;
    int choice = 0;
    int val, ind, nv;
    while (choice != 10) {
      printf("Enter 1 to display the linked list.\nEnter 2 to add a node at the beginning.\nEnter 3 to add a node at an index.\nEnter 4 to add a node at the end.\nEnter 5 to add a node after a val.\nEnter 6 to delete first Node.\nEnter 7 to delete a node using index.\nEnter 8 to delete the last node.\nEnter 9 to delete using a value.\nEnter 10 to exit.\nChoice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
        Traversal(head);
        break;
      case 2:
        printf("Enter value to be added at the beginning: ");
        scanf("%d", &val);
        head = insertAtBeginning(val, head);
        break;
      case 3:
        printf("Enter value to be added: ");
        scanf("%d", &val);
        printf("Enter index: ");
        scanf("%d", &ind);
        insertAtIndex(val, ind, head);
        break;
      case 4:
        printf("Enter value to be added at the end: ");
        scanf("%d", &val);
        insertAtEnd(val, head);
        break;
      case 5:
        printf("Enter the val: ");
        scanf("%d", &val);
        printf("Enter the node val: ");
        scanf("%d", &nv);
        
        insertAfterVal(val, nv, head);
        break;
      case 6:
         head = deleteFirstNode(head);
         break;  
      case 7:
         printf("Enter index: ");
         scanf("%d", &ind);
         deleteInBetween(ind, head);
         break;
      case 8:
         deleteLastNode(head);
         break;
      case 9:
        printf("Enter value to be deleted: ");
        scanf("%d", &val);
        head = deleteNodeUsingVal(val, head);
        break;      
      }

    }
    deleteList(head);
    return 0;
}