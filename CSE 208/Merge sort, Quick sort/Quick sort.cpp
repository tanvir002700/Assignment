/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int A[1000000];
int partition(int *A,int p,int r)
{
    int pivot,i;
    pivot=A[r];
    i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
void Quick_sort(int *A,int p,int r)
{
    if(p>=r)return;
    int pivot=partition(A,p,r);
    Quick_sort(A,p,pivot-1);
    Quick_sort(A,pivot+1,r);
}
int file_to_input(int *A,char *file_name)
{
    FILE *fp;
    fp=fopen(file_name,"r");
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
    fclose(fp);
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
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_1(Quick sort).txt");


    size=file_to_input(A,"file1000.txt");
    t=clock();
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_2(Quick sort).txt");

    size=file_to_input(A,"file10000.txt");
    t=clock();
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_3(Quick sort).txt");


    size=file_to_input(A,"file100000.txt");
    t=clock();
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_4(Quick sort).txt");


    size=file_to_input(A,"file1000000.txt");
    t=clock();
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_5(Quick sort).txt");

    size=file_to_input(A,"file number sorted order 10000.txt");
    t=clock();
    Quick_sort(A,0,size-1);
    t=clock()-t;
    cout<<"file "<<size<<" take "<<t<<" ms"<<endl;
    file_to_output(A,size,"output_file_6(Quick sort).txt");
    return 0;
}
