#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

/* 1. Enqueue */
void enqueue()
{
    int value;
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted successfully.\n", value);
}

/* 2. Dequeue */
// Function to delete an element from the queue
void dequeue()
{
    struct node *temp;
    // Check if queue is empty
    if (front == NULL)
    {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }
    temp = front;
    printf("%d deleted successfully.\n", front->data);
    front = front->next;
    free(temp);
    // If queue becomes empty
    if (front == NULL)
        rear = NULL;
}

/* 3. Peek */
void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element is: %d\n", front->data);
    }
}

/* 4. isEmpty */
void isEmpty()
{
    if (front == NULL)
        printf("Queue is Empty.\n");
    else
        printf("Queue is Not Empty.\n");
}

/* 5. Print */
void print()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");
        temp = front;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

/* Main Menu */
int main()
{
    int choice;
    do
    {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. Print\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: print(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 6);
    return 0;
}