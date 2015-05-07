/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<string>
#include<iostream>
#define swap(a,b) a=a^b,b=b^a,a=a^b
using namespace std;
class node
{
    public:
    int value;
    node *next;
};
class List
{
    private:
    node *head;
    node *tail;
    public:
    List();
    void show();
    void Insert(int n);
    void Insert_after(int n,int key);
    void Insert_before(int n,int key);
    void Delete(int n);
    bool Search(int n);
    int length();
    void Sort();
};
void List::Sort()
{
    int N=length();
    node *temp=head,*I,*J;
    int i,j;
    for(i=0;i<N-1;i++)
    {
        I=temp;
        J=temp->next;
        for(j=i+1;j<N;j++)
        {
            if(I->value>J->value)
            {
                swap(I->value,J->value);
            }
            J=J->next;
        }
        temp=temp->next;
    }
}
List::List()
{
    head=NULL;
    tail=NULL;
}
void List::Insert(int n)
{
    node *temp;
    temp=new node;
    temp->value=n;
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
void List::Insert_after(int n,int key)
{
    node *temp,*left,*right;
    temp=new node;
    temp->value=n;
    if(head->value==key)
    {
        right=head->next;
        head->next=temp;
        temp->next=right;
        return;
    }
    left=head;
    while(left!=NULL&&left->value!=key)
    {
        left=left->next;
    }
    if(left==NULL)
    {
        printf("Invalid operation\n");
        return;
    }
    if(left->next==NULL)
    {
        temp->next=NULL;
        left->next=temp;
        return;
    }
    right=left->next;
    left->next=temp;
    temp->next=right;
}
void List::Insert_before(int n,int key)
{
    node *temp,*left,*right;
    temp=new node;
    temp->value=n;
    if(head->value==key)
    {
        temp->next=head;
        head=temp;
        return;
    }
    right=head;
    while(right!=NULL&&right->value!=key)
    {
        left=right;
        right=right->next;
    }
    if(right!=NULL)
    {
        left->next=temp;
        left=temp;
        left->next=right;
    }
    else
    {
        printf("Invalid operation\n");
    }
}
void List::Delete(int n)
{
    node *left,*right,*temp;
    if(head->value==n)
    {
        temp=head;
        head=head->next;
        delete(temp);
        return;
    }
    temp=head;
    while(temp!=NULL&&temp->value!=n)
    {
        left=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Invalid operation\n");
        return;
    }
    if(temp->next==NULL)
    {
        left->next=NULL;
        tail=left;
        delete(temp);
        return;
    }
    right=temp->next;
    left->next=right;
    delete(temp);
}
void List::show()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->value);
        temp=temp->next;
    }
}
bool List::Search(int n)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->value==n)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int List::length()
{
    int cnt=0;
    node *temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void menu()
{
    printf("Select any one or want to exit type end.\n");
    printf("1. Append\n");
    printf("2. Insert Before\n");
    printf("3. Insert After\n");
    printf("4. Showing Length\n");
    printf("5. Delete\n");
    printf("6. Display\n");
    printf("7. Search\n");
    printf("8. Sort\n");
}
int main()
{
    menu();
    string input;
    List A;
    int N,key;
    while(cin>>input)
    {
        if(input=="end")break;
        if(input=="1")
        {
            printf("enter your number: ");
            cin>>N;
            A.Insert(N);
        }
        else if(input=="2")
        {
            printf("enter your number: ");
            cin>>N;
            printf("enter your key number: ");
            cin>>key;
            A.Insert_before(N,key);
        }
        else if(input=="3")
        {
            printf("enter your number: ");
            cin>>N;
            printf("enter your key number: ");
            cin>>key;
            A.Insert_after(N,key);
        }
        else if(input=="4")
        {
            printf("Your list length: %d\n",A.length());
        }
        else if(input=="5")
        {
            printf("enter element which you want to delete: ");
            cin>>N;
            A.Delete(N);
        }
        else if(input=="6")
        {
            printf("Current List element:\n");
            A.show();
        }
        else if(input=="7")
        {
            printf("enter your Search element: ");
            cin>>N;
            if(A.Search(N))
            {
                printf("Found\n");
            }
            else
            {
                printf("NOT found\n");
            }
        }
        else
        {
            A.Sort();
        }
    }
    return 0;
}
