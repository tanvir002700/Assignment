/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
class BookList
 {
    string Accno;
    string Author;
    string Title;
    int Price;
    BookList *next;
    public:
        void insertData(string accno,string author,string title,int price)
        {
            Accno=accno;
            Author=author;
            Title=title;
            Price=price;
            next=NULL;
        }
        void addNext(BookList *temp)
        {
            next=temp;
        }
        BookList* getNext()
        {
            return next;
        }
        void showData()
        {
            cout<<"Accno : "<<Accno<<endl;
            cout<<"Author : "<<Author<<endl;
            cout<<"Title : "<<Title<<endl;
            cout<<"Price : "<<Price<<endl;
        }
};
class ShelfList
 {
     BookList *head,*tail;
     public:
         ShelfList()
         {
             head=tail=NULL;
         }
         void add(string accno,string author,string title,int price)
         {
             BookList *temp=new BookList();
             temp->insertData(accno,author,title,price);
             if(head==NULL)
             {
                 head=tail=temp;
                 return;
             }
             tail->addNext(temp);
             tail=temp;
         }
         void show()
         {
             BookList *temp=head;
             int cnt=1;
             while(temp!=NULL)
             {
                 cout<<"show data "<<cnt++<<endl;
                 temp->showData();
                 temp=temp->getNext();
                 cout<<endl<<endl;
             }
         }
};

int main()
{
    ShelfList A;
    A.add("123","prottoy","hitlar",123);
    A.add("1234","raisa sigma","blue",123);
    A.add("123433","tanna","nika",123);
    A.show();
    return 0;
}
