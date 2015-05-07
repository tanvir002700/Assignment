/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
const int NN=100;
class Heap
{
    int arr[NN+1];
    int n;
    public:
    Heap()
    {
        clear();
    }
    void clear()
    {
        n=0;
    }
    void insert(int K)
    {
        if(n==NN)
        {
            cout<<"cannot insert, head is full"<<endl;
            return;
        }
        n++;
        arr[n]=K;
        int p=n;
        while(p>1)
        {
            int pr=p/2;
            if(arr[pr]>arr[p])
            {
                swap(arr[pr],arr[p]);
                p=pr;
            }
            else break;
        }
    }
    int remove()
    {
        if(n==0)
        {
            cout<<"Hear is empty"<<endl;
            return -1;
        }
        int K=arr[1];
        arr[1]=arr[n];
        n--;
        int p=1;
        while(2*p<=n)
        {
            int ch=2*p;
            if(2*p+1<=n)
            {
                if(arr[ch]>arr[ch+1])ch++;
            }
            if(arr[p]>arr[ch])
            {
                swap(arr[p],arr[ch]);
                p=ch;
            }
            else break;
        }
        return K;
    }
};
int main()
{
    return 0;
}

