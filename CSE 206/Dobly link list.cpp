/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<iostream>
using namespace std;
class node
{
    public:
    int value;
    node *prev,*next;
};
class List
{
    private:
    node *head,*tail;
    public:
    List();
    void add(int n);
    void print();
    void rprint();
    void Delete(int n);
};
List::List()
{
    head=tail=NULL;
}
void List::add(int n)
{
    node *temp;
    temp=new node;
    temp->value=n;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=tail=temp;
        return;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void List::print()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}
void List::rprint()
{
    node *temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->value<<endl;
        temp=temp->prev;
    }
}
void List::Delete(int n)
{
    node *temp=head;
    if(head->value==n)
    {
        head=head->next;
        head->prev=NULL;
        delete(temp);
        return;
    }
    if(tail->value==n)
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(temp->value==n)
        {
            node *left=temp->prev;
            node *right=temp->next;
            delete(temp);
            left->next=right;
            right->prev=left;
            return;
        }
        temp=temp->next;
    }
}
int main()
{
    List A;
    A.add(12);
    A.add(13);
    A.add(167);
    A.add(123);
    A.Delete(167);
    A.rprint();
    return 0;
}
