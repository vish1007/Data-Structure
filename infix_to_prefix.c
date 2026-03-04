#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max 10   // Maximum size of stack

// Stack array to store operators
char stack[max];

// 'top' keeps track of the top element of stack
int top = -1;

// -------------------- PUSH FUNCTION --------------------
// This function pushes an element into the stack
void push(char ch)
{
    // Check if stack is full
    if (top == max - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;              // Move top to next position
        stack[top] = ch;    // Insert element at top
    }
}
// -------------------- POP FUNCTION --------------------
// This function removes and returns the top element
char pop()
{
    char ch;
    ch = stack[top];   // Store the top element
    top--;             // Decrease top (remove element)
    return ch;         // Return popped element
}

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    else
        return 0;
}

void reverse(char str[])
{
    int i=0, j=strlen(str)-1;
    char temp;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

int main()
{
    char infix[100], prefix[100];
    int j=0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(int i=strlen(infix)-1;i>=0;i--)
    {
        if(isalnum(infix[i]))
        {
            prefix[j] = infix[i];
            j++;
        }

        else if(infix[i] == ')')
        {
            push(infix[i]);
        }

        else if(infix[i] == '(')
        {
            while(stack[top] != ')')
            {
                prefix[j] = pop();
                j++;
            }
            pop();
        }

        else
        {
            while(top != -1 && precedence(stack[top]) > precedence(infix[i]))
            {
                prefix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
    }
    while(top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';

    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}