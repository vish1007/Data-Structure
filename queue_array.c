#include <stdio.h>
#define MAX 4
int queue[MAX];
int front = -1;
int rear = -1;

/* 1. Enqueue */
void enqueue()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
    }
    else
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted successfully.\n", value);
    }
}

/* 2. Dequeue */
void dequeue()
{
    if (front == -1 || front > rear)
    /*We do not check rear == -1 because:
    In the initial state, both front and rear are already -1.
    So if front is -1, it automatically means the queue has no elements.
    Checking rear == -1 would be redundant (extra check not needed).*/
    {
        printf("Queue Underflow! Cannot delete.\n");
    }
    else
    {
        printf("%d deleted successfully.\n", queue[front]);
        front++;
    }
}

/* 3. Peek */
void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

/* 4. IsEmpty */
void isEmpty()
{
    if (front == -1 || front > rear)
        printf("Queue is Empty.\n");
    else
        printf("Queue is Not Empty.\n");
}

/* 5. IsFull */
void isFull()
{
    if (rear == MAX - 1)
        printf("Queue is Full.\n");
    else
        printf("Queue is Not Full.\n");
}

/* 6. Print */
void print()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

/* 7. Main Menu */
int main()
{
    int choice;
    do
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Print\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            case 6: print(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);
    return 0;
}