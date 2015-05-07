/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(a,b) a=a^b,b=b^a,a=a^b
void Bubble_sort(int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
int main()
{
    int n,input[200],i;
    int a=30,b=60;
    swap(a,b);
    printf("How many element??\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    Bubble_sort(input,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }
    return 0;
}
