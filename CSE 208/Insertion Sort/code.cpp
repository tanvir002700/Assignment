/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
int insertion_sort(int *A,int n)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        int key=A[i];
        int j;
        for(j=i-1;j>=0 and A[j]>key;j--)
        {
            cnt++;
            A[j+1]=A[j];
        }
        A[j+1]=key;
    }
    return cnt;
}
int main()
{
    int n;
    cout<<"enter number of element"<<endl;
    cin>>n;
    int A[10000];
    for(int i=1;i<=n;i++)cin>>A[i];
    clock_t t;
    t=clock();
    int cnt=insertion_sort(A,n);
    t=clock()-t;
    cout<<"sorted"<<endl;
    for(int i=1;i<=n;i++)cout<<A[i]<<" ";
    cout<<endl;
    cout<<"complexity "<<cnt<<endl;
    cout<<"complexity in time "<<t<<endl;
    cout<<"sorted form file"<<endl;
    FILE *fp;
    fp=fopen("rand.txt","r");
    int indx=1;
    while(!feof(fp))
    {
        int x;
        fscanf(fp, "%d", &x);
        if(!feof(fp))
        {
            A[indx++]=x;
        }
    }
    fclose(fp);
    cout<<"number of element "<<indx<<endl;
    t=clock();
    cnt=insertion_sort(A,indx-1);
    t=clock()-t;
    cout<<"sorted element "<<endl;
    for(int i=1;i<=indx-1;i++)cout<<A[i]<<" ";
    cout<<endl;
    cout<<"complexity "<<cnt<<endl;
    cout<<"complexity in time "<<t<<endl;


    fp=fopen("rand2.txt","r");
    indx=1;
    while(!feof(fp))
    {
        int x;
        fscanf(fp, "%d", &x);
        if(!feof(fp))
        {
            A[indx++]=x;
        }
    }
    fclose(fp);
    cout<<"number of element in second file "<<indx<<endl;
    t=clock();
    cnt=insertion_sort(A,indx-1);
    t=clock()-t;
    cout<<"sorted element "<<endl;
    for(int i=1;i<=indx-1;i++)cout<<A[i]<<" ";
    cout<<endl;
    cout<<"complexity "<<cnt<<endl;
    cout<<"complexity in time "<<t<<endl;
    return 0;
}
