/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
class node
{
    public:
        int value;
        node *next;
};
class Stack
{
    private:
        node *head;
    public:
        Stack();
        void Insert(int n);
        void show();
        void Pop();
        int Front();
};
Stack::Stack()
{
    head=NULL;
}
void Stack::Insert(int n)
{
    node *temp;
    temp =new node;
    temp->value=n;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
void Stack::show()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->value);
        temp=temp->next;
    }
}
int Stack::Front()
{
    int temp=head->value;
    return temp;
}
void Stack::Pop()
{
    node *temp=head;
    head=head->next;
    delete(temp);
}
int main()
{
    Stack A;
    for(int i=0;i<10;i++)
    {
        A.Insert(i);
    }
    printf("%d\n",A.Front());
    return 0;
}
