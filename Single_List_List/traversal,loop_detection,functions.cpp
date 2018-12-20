#include<stdio.h>
#include<bits/stdc++.h>
#include<list>
#include<set>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head, int data)
{
    struct Node* new_Node=(struct Node*)malloc(sizeof(struct Node));
    new_Node->data=data;
    new_Node->next=NULL;
    if(*head!=NULL)
    {
        new_Node->next=*head;
        *head=new_Node;
    }
    else //for empty SLL
    {
        *head=new_Node;
    }
}

void traversal(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

struct Node* pairwise_swap(struct Node* head)
{
    struct Node* current=head;
    struct Node* next=NULL;
    if(head!=NULL && head->next!=NULL)
    {
        next=head->next;
        while(current)
        {

        }
    }
    return head;
}

struct Node* last_element_to_first(struct Node* head)
{
    struct Node* temp=head;
    if(temp==NULL || temp->next==NULL)
        return head;
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        struct Node* ptr=temp->next;
        temp->next=NULL;
        ptr->next=head;
        head=ptr;
        return head;
    }
}

bool detect_loop_SLL(struct Node* head)
{
    set<struct Node*>s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end())
        {
            return true;
        }
        s.insert(head);
        head=head->next;
    }
    return false;
}


int main()
{
    struct Node* head=NULL; //initialize an empty CLL
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,0);


    struct Node* head1=NULL;
    push(&head1,10000);
    push(&head1,1000);
    push(&head1,100);
    push(&head1,10);
    traversal(head1);

    struct Node* temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head1->next;
    traversal(head);
    cout<<endl<<detect_loop_SLL(head1);



    return 0;

}
