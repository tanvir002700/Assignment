/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
class node
{
public:
    int data;
    node *next;
};
class Queue
{
private:
    node *head,*tail;
public:
    Queue();
    void Push(int n);
    void show();
    int Front();
    void Pop();
};
Queue::Queue()
{
    head=tail=NULL;
}
void Queue::Push(int n)
{
    node *temp;
    temp =new node;
    temp->data=n;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    if(head->data>n)
    {
        temp->next=head;
        head=temp;
        return;
    }
    node *left,*right;
    right=head;
    while(right!=NULL)
    {
        left=right;
        right=right->next;
        if(right!=NULL&&right->data>n)break;
    }
    left->next=temp;
    temp->next=right;
}
void Queue::show()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int Queue::Front()
{
    node *temp=head;
    return temp->data;
}
void Queue::Pop()
{
    node *temp=head;
    head=head->next;
    delete(temp);
}
int main()
{
    Queue a;
    a.Push(12);
    a.Push(100);
    a.Push(-20);
    a.Push(13);
    a.Push(300);
    a.Push(1);
    a.show();
    printf("front %d\n",a.Front());
    a.Pop();
    printf("front %d\n",a.Front());
    return 0;
}
