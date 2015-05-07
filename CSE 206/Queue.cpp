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
    void del(node *ptr)
    {
        if(ptr==NULL)return;
        del(ptr->next);
        delete(ptr);
    }
    public:
        Queue();
        ~Queue();
        void Push(int n);
        void show();
        int Front();
        void Pop();
};
Queue::Queue()
{
    head=tail=NULL;
}
Queue::~Queue()
{
    del(head);
}
void Queue::Push(int n)
{
    node *temp;
    temp =new node();
    temp->data=n;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
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
    a.Push(102);
    a.Push(102);
    a.Push(102);
    a.Push(102);
    a.Push(102);
    printf("front %d\n",a.Front());
    a.Pop();
    printf("front %d\n",a.Front());
    return 0;
}
