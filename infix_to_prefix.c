#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
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
            prefix[j++] = infix[i];
        }

        else if(infix[i] == ')')
        {
            push(infix[i]);
        }

        else if(infix[i] == '(')
        {
            while(stack[top] != ')')
            {
                prefix[j++] = pop();
            }
            pop();
        }

        else
        {
            while(top != -1 && precedence(stack[top]) > precedence(infix[i]))
            {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while(top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}