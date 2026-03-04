#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Function to push element into stack */
void push(int value)
{
    top++;
    stack[top] = value;
}
/* Function to pop element from stack */
int pop()
{
    int value;
    value = stack[top];
    top--;
    return value;
}
int main()
{
    char postfix[100];
    int i, A, B, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    /* Read postfix expression from left to right */
    for(i = 0; i < strlen(postfix); i++)
    {
        /* If symbol is a number (operand) */
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');   // convert character to integer
        }
        /* If symbol is an operator */
        else
        {
            A = pop();   // second operand
            B = pop();   // first operand

            if(postfix[i] == '+')
                result = B + A;

            else if(postfix[i] == '-')
                result = B - A;

            else if(postfix[i] == '*')
                result = B * A;

            else if(postfix[i] == '/')
                result = B / A;

            /* push the result back to stack */
            push(result);
        }
    }
    /* Final result */
    printf("Result = %d\n", pop());
    return 0;
}