#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};


void push_CLL(struct Node** head, int data)  // new node insertion at the start of the CLL
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=*head;
    new_Node->data=data;
    if(*head==NULL)
    {
        *head=new_Node;
        new_Node->next=new_Node;
    }
    else
    {
        new_Node->next=*head;
        while(temp->next!=*head)
            temp=temp->next;
        temp->next=new_Node;
    }
    *head=new_Node;
}

void traversal_CLL(struct Node* head) //CLL traversal
{
    struct Node* temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

struct Node* delete_last_element(struct Node* head)
{
    struct Node* temp=head;
    if(head==NULL)
        return head;
    else
    {
        while(temp->next->next!=head)
           temp=temp->next;
       delete(temp->next);
       temp->next=head;
       return head;
    }
    
}



int main()
{
    struct Node* head=NULL; //initialize an empty CLL
    push_CLL(&head,5);
    push_CLL(&head,4);
    push_CLL(&head,3);
    push_CLL(&head,2);
    push_CLL(&head,1);
    push_CLL(&head,0);
    traversal_CLL(head);
    head=delete_last_element(head);head=delete_last_element(head);
    traversal_CLL(head);

    return 0;

}
