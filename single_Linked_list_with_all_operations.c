#include<stdio.h>
#include<stdlib.h>
//Here we declaing our own datatype so inplace of node you can write and data type name 
struct node{
    int data;
    struct node *next;
};


//************************************How to create a single link list-automatic process********************************************

struct node* create()
{   
    struct node *head=NULL,*newNode=NULL,*temp=NULL;
    int choice=1;
    while(choice==1)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data");
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
        printf("Press 1 to continu or 0 for stop");
        scanf("%d",&choice);
    }
    return head;
}

// ***************************************How to Display the elements of Linked list*******************************************
void display(struct node* head)
{ 
    struct node *temp=NULL;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}


//*************************************************How to insert the elements at last************************************************
struct node* insertAtLast(struct node* head)
{
    struct node *newNode=NULL,*temp=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Please enter the data of new node");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//***************************************************How to insert the elements at first position******************************************
struct node* insertfirst(struct node* head)
{
struct node *newNode=NULL;
newNode=(struct node*)malloc(sizeof(struct node));

printf("enter new node data");
scanf("%d",&newNode->data);
newNode->next=head;
head=newNode;
return head;


//****************************************************How to insert node at any position except last and first***********************************************
}
struct node* atanypos(struct node *head,int pos)
{
    struct node *newNode=NULL,*temp=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("please enter the data of new node that you want to enter at any position-> ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    temp=head;
    for(int i=1 ;i<pos-1;i++ )
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
    
}

//******************************************************************How to delete the first node*************************************************
struct node *delete_at_first(struct node *head)
{
    struct node *temp=NULL;
    if(head==NULL)
    {
        printf("list is empty");
        return NULL;
    }
    temp=head;
    head=head->next;
    free(temp);
    return head;
    
}

//*********************************************************************How to delete the last node**********************************************************
struct node *delete_last(struct node *head)
{
    struct node *temp, *prev;
    // Case 1: list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    // Case 2: only one node
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    // Case 3: more than one node
    temp = head;
    prev=NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}


//*****************************************************************How to delete the node at any position*******************************************************
struct node *delete_at_position(struct node *head, int pos)
{
    struct node *temp, *prev;
    int i;
    // check empty list
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    // delete first node
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // delete node at given position
    temp = head;
    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}


//****************************************************************How to reverse the list**************************************************
struct node *reverse_list(struct node *head)
{
    struct node *p = NULL;
    struct node *c = head;
    struct node *n = NULL;

    while (c != NULL)
    {
        n = c->next;   // store next node
        c->next = p;   // reverse link
        p = c;         // move p forward
        c = n;         // move c forward
    }
    head = p;          // update head
    return head;
}
//************Here we are calling the function which ever we require in the main function***************** */
int main()
{
    struct node *head=NULL;
    head=create();
    display(head);
    head=insertfirst(head);
    display(head);
    
    return 0;
}
