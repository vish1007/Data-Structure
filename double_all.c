#include <stdio.h>
#include <stdlib.h>
// Structure of Doubly Linked List Node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
int main() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int choice = 1;

    while (choice) {
        // Allocate memory for new node
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            // First node
            head = temp = newnode;
        } else {
            // Link new node at the end
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Press 1 to continue, 0 to stop: ");
        scanf("%d", &choice);
    }

    // Display the list (Forward Traversal)
    printf("\nDoubly Linked List (Forward): ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
int main() 
{
    struct node *head;
    // Function Call
    head = createList();
}