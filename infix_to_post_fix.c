#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
// Function to push into stack
void push(char ch)
{
    if (top==MAX-1)
    {
        printf("Stack Overflow! Cannot push %c\n", ch);
    }
    else
    {
        stack[++top] = ch;
    }
}
// Function to pop from stack
char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}
// Function to check precedence
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        // If operand, add to postfix
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        // If '(' push to stack
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }

        // If ')', pop until '('
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();  // remove '('
        }

        // If operator
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // at the last we are adding null character
    //so that we can make postfix character array to string

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}