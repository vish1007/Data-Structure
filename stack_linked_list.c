#include <stdio.h>
#include <stdlib.h>

// Structure definition for stack node
struct node
{
    int data;              // Stores element
    struct node *next;     // Points to next node
};
// Global top pointer (initially NULL → stack empty)
struct node *top = NULL;


/*================ PUSH OPERATION ================*/
void push()
{
    struct node *newnode;
    int value;

    // Allocate memory for new node
    newnode = (struct node*)malloc(sizeof(struct node));

    // Check if memory is available
    if(newnode == NULL)
    {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }

    // Take input from user
    printf("Enter value to push: ");
    scanf("%d", &value);

    // Store value inside node
    newnode->data = value;

    // New node should point to previous top
    newnode->next = top;

    // Move top to new node
    top = newnode;

    printf("Element inserted successfully\n");
}


/*================ POP OPERATION ================*/
void pop()
{
    struct node *temp;

    // Check if stack is empty
    if(top == NULL)
    {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }

    // Store current top in temp
    temp = top;

    // Move top to next node
    top = top->next;

    // Print deleted value
    printf("Deleted element: %d\n", temp->data);

    // Free memory of deleted node
    free(temp);
}


/*================ PEEK OPERATION ================*/
void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}


/*================ ISEMPTY OPERATION ================*/
void isEmpty()
{
    if(top == NULL)
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");
}


/*================ DISPLAY OPERATION ================*/
void display()
{
    struct node *temp = top;

    if(temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


/*================ SEARCH OPERATION ================*/
void search()
{
    int key, position = 1;
    struct node *temp = top;
    if(temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d from top\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found\n");
}


/*================ COUNT OPERATION ================*/
void count()
{
    int c = 0;
    struct node *temp = top;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    printf("Total elements in stack: %d\n", c);
}


/*================ MAIN FUNCTION ================*/
int main()
{
    int choice;
    do
    {
        printf("\n===== STACK USING LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Count\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: display(); break;
            case 6: search(); break;
            case 7: count(); break;
            case 8: printf("Exiting program...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 8);

    return 0;
}