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
// -------------------- PRECEDENCE FUNCTION --------------------
// This function returns the priority of operators
int precedence(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
// -------------------- MAIN FUNCTION --------------------
int main()
{
    char infix[100];     // To store infix expression
    char postfix[100];   // To store postfix expression
    int j = 0;           // Index for postfix expression

    printf("Please enter the infix expression: ");
    scanf("%s", infix);
    // Traverse the infix expression one character at a time
    for(int i = 0; i < strlen(infix); i++)
    {
        // If the character is an operand (letter or number)
        // directly add it to postfix expression
        if(isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        // If character is '(' push it into stack
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        // If character is ')'
        else if(infix[i] == ')')
        {
            // Pop operators until '(' is found
            while(stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            // Remove '(' from stack
            pop();
        }

        // If character is an operator (+ - * / ^)
        else
        {
            // Pop operators with higher or equal precedence
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            // Push current operator into stack
            push(infix[i]);
        }
    }

    // After scanning complete expression
    // Pop all remaining operators from stack
    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    // Add end of string character
    postfix[j] = '\0';

    // Print postfix expression
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}