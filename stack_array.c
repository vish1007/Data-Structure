#include <stdio.h>
#define MAX 4
int stack[MAX];
int top = -1;
/* 1. Push */
void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot push.\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed successfully.\n", value);
    }
}

/* 2. Pop */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop.\n");
    }
    else
    {
        printf("%d popped successfully.\n", stack[top]);
        top--;
    }
}

/* 3. Peek */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

/* 4. IsEmpty */
void isEmpty()
{
    if (top == -1)
        printf("Stack is Empty.\n");
    else
        printf("Stack is Not Empty.\n");
}

/* 5. IsFull */
void isFull()
{
    if (top == MAX - 1)
        printf("Stack is Full.\n");
    else
        printf("Stack is Not Full.\n");
}

/* 6. Count */
void count()
{
    printf("Total elements in stack: %d\n", top + 1);
}

/* 7. Search */
void search()
{
    int value, i, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (i = top; i >= 0; i--)
    {
        if (stack[i] == value)
        {
            printf("Element found at position %d (from top).\n", top - i + 1);
            found = 1;
            break;
        }
    }
    if (found==0)
        printf("Element not found.\n");
}

/* 8. Print */
void print()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

/* 9. Main Menu */
int main()
{
    int choice;
    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. IsFull\n");
        printf("6. Count\n");
        printf("7. Search\n");
        printf("8. Print\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
            push(); 
            break;
            case 2: 
            pop(); 
            break;
            case 3: 
            peek(); 
            break;
            case 4: 
            isEmpty();
            break;
            case 5: 
            isFull(); 
            break;
            case 6: 
            count(); 
            break;
            case 7: 
            search(); 
            break;
            case 8: 
            print(); 
            break;
            case 9: 
            printf("Exiting...\n"); 
            break;
            default: 
            printf("Invalid choice!\n");
        }
    } while (choice != 9);
    return 0;
}