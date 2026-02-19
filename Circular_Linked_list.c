#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};


// **************************************Here i will create Circular single linked list******************************************************
struct node* create()
{   
    struct node *head=NULL,*newNode=NULL,*temp=NULL;
    int choice=1;
    while(choice==1)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newNode->data);

        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }

        printf("Press 1 to continue or 0 for stop: ");
        scanf("%d",&choice);
    }
    // Important change for Circular Linked List
    if(head != NULL)
    {
        temp->next = head;
    }
    return head;
}

//*******************************************************Here i am displaying all the elements of circular linked list******************************************************************************
void display(struct node* head)
{ 
    struct node *temp = head;

    if(head == NULL) //Here i am checking the edge case
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } 
    while(temp != head);
    printf("(head)\n");
}
int main()
{
    struct node *head = NULL;
    head = create();      // Create circular list
    display(head);        // Display circular list
    return 0;
}
