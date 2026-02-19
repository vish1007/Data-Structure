#include <stdio.h>
#include <stdlib.h>
// Structure of Doubly Linked List Node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
// ********************************************************Creating Double linked list*****************************************************************
struct node* createList() {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int choice = 1;
    while (choice == 1) {
        // Allocate memory
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL) {
            // First node
            head = temp = newnode;
        } 
        else {
            // Insert at end
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Press 1 to continue, 0 to stop: ");
        scanf("%d", &choice);
    }
    return head;
}

// *****************************************************************Forward Traversal************************************************************
void display_forward(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d<->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


//*************************************************************** */ Backward Traversal********************************************************
void display_backward(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Print in reverse
    while (temp != NULL)
    {
        printf("%d<->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}


// ********************************************************Insert the node at the beginning*****************************************************************
struct node* insert_begin(struct node *head)
{
    struct node *newNode=NULL;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("Please enter the data that you want to insert at the beginning:");
    scanf("%d",&newNode->data);
    newNode->prev=NULL;
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}

// ********************************************************Insert the node at the end*****************************************************************
struct node* insert_end(struct node *head)
{
    struct node *newnode, *temp;
    int data;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data of node that you want to insert at the end: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;   // Because it will be last node

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}


// ********************************************************Insert the node at any position except first and last*****************************************************************
struct node* insert_at_position(struct node *head)
{
    struct node *newnode, *temp, *temp2;
    int data, pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    temp = head;
    // Move to (pos - 1)th node
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp2 = temp->next;   // store next node separately
    newnode->next = temp2;
    newnode->prev = temp;
    temp->next = newnode;
    temp2->prev = newnode;
    return head;
}


// ********************************************************Delete the node at the beginning*****************************************************************

struct node* delete_first(struct node *head)
{
    struct node *temp;

    temp = head;          // store first node
    head = head->next;    // move head forward
    head->prev = NULL;    // remove backward link
    free(temp);           // delete old first node

    return head;
}


// ********************************************************Delete the end node or last node*****************************************************************

struct node* delete_last(struct node *head)
{
    struct node *temp;
    temp = head;
    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Remove last node
    temp->prev->next = NULL;
    free(temp);
    return head;
}


// ********************************************************Insert the node at any postion(except first and last)*****************************************************************
struct node* delete_at_position(struct node *head)
{
    struct node *temp;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = head;
    // Move to the node to be deleted
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    // Adjust links
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}


// ********************************************************Reverse the double linked list*****************************************************************
struct node* reverse(struct node *head)
{
    struct node *current = head;
    struct node *temp = NULL;

    if (head == NULL) // here we are checking list ie empty or not to check edge case
        return NULL;

    while (current != NULL)
    {
        //Swaping next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        //Move to next node (which is previous now)
        current = current->prev;
    }
    // Fix new head
    if (temp != NULL)
        head = temp->prev;
    return head;
}

//************************************************ */ Main Function*****************************************************************
int main() {
    struct node *head;
    // Function Call
    head = createList();
    display_forward(head);

    // head=insert_begin(head);
    // display_forward(head);

    // head=insert_end(head);
    // display_forward(head);

    // head=insert_at_position(head);
    // display_forward(head);
    
    // head=delete_first(head);
    // display_forward(head);

    // head=delete_last(head);
    // display_forward(head);

    // head=delete_at_position(head);
    // display_forward(head);
  
    // head=reverse(head);
    // display_forward(head);
    return 0;
}
