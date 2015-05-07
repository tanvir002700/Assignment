/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x7FFFFFFF;
int L[1000000],R[1000000];
int A[10000000];
void marge(int *A,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int i,j;
    for(i=1; i<=n1; i++)
    {
        L[i]=A[p+i-1];
    }
    for(int j=1; j<=n2; j++)
    {
        R[j]=A[q+j];
    }
    L[n1+1]=inf;
    R[n2+1]=inf;
    i=j=1;
    for(int k=p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}
void marge_sort(int *A,int p,int r)
{
    if(p>=r)return;
    int mid=(p+r)>>1;
    marge_sort(A,p,mid);
    marge_sort(A,mid+1,r);
    marge(A,p,mid,r);
}
int file_to_input(int *A,char *ch)
{
    FILE *fp;
    fp=fopen(ch,"r");
    int indx=0;
    while(!feof(fp))
    {
        if(!feof(fp))
        {
            int x;
            fscanf(fp,"%d",&x);
            A[indx++]=x;
        }
    }
    return indx-1;
}
void file_to_output(int *A,int sz,char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"w");
    for(int i=0;i<sz;i++)
    {
        fprintf(fp,"%d\n",A[i]);
    }
    fclose(fp);
}
int main()
{
    int size=file_to_input(A,"file10.txt");
    clock_t t;
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_1(marge sort).txt");


    size=file_to_input(A,"file1000.txt");
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_2(marge sort).txt");

    size=file_to_input(A,"file10000.txt");
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_3(marge sort).txt");


    size=file_to_input(A,"file100000.txt");
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_4(marge sort).txt");


    size=file_to_input(A,"file1000000.txt");
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_5(marge sort).txt");


    size=file_to_input(A,"file number sorted order 10000.txt");
    t=clock();
    marge_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_6(marge sort).txt");
    return 0;
}
