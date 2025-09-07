#include <stdio.h>
#include <stdlib.h>

// =============================
// STRUCTURE OF A NODE
// =============================
// A linked list node has two parts:
// 1. data → stores the value
// 2. next → pointer to the next node
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer → always points to the first node
// If list is empty, head = NULL
struct Node* head = NULL;

// =============================
// FUNCTION: Create a new node
// =============================
struct Node* createNode(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;   // store data
    newNode->next = NULL;    // by default, no next node
    return newNode;
}

// =============================
// INSERTION OPERATIONS
// =============================

// Insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;   // new node points to current head
    head = newNode;         // head becomes the new node
}

// Insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {    // if list is empty
        head = newNode;    // new node becomes first node
        return;
    }

    // traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;   // last node points to new node
}

// Insert at a given position (1-based index)
void insertAtPosition(int value, int pos) {
    if (pos == 1) {   // if inserting at start
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    // traverse until pos-1
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    // link new node between temp and next node
    newNode->next = temp->next;
    temp->next = newNode;
}

// =============================
// DELETION OPERATIONS
// =============================

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {  // list empty
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;   // take backup of first node
    head = head->next;          // move head to second node
    free(temp);                 // free old first node
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {  // list empty
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {  // only one node
        free(head);
        head = NULL;
        return;
    }

    // traverse to second last node
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);      // free last node
    temp->next = NULL;     // second last points to NULL
}

// Delete at a given position
void deleteAtPosition(int pos) {
    if (head == NULL) {   // list empty
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {   // delete first node
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;

    // traverse until pos-1
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* delNode = temp->next;   // node to delete
    temp->next = delNode->next;          // skip deleted node
    free(delNode);                       // free memory
}

// =============================
// SORTING OPERATION
// =============================
// Bubble sort: compare every pair and swap data if needed
void sortList() {
    if (head == NULL) return;  // empty list → nothing to sort

    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // swap values
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// =============================
// DISPLAY FUNCTION
// =============================
// Prints the entire linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Sort List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                sortList();
                break;

            case 8:
                displayList();
                break;

            case 9:
                exit(0);  
            default:
                printf("Invalid choice!\n");
        }
    }
}

