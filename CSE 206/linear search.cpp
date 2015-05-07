/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int linear_search(int *a,int n,int Search_element)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==Search_element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,input[200],i,search_element;
    printf("how many element??\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    printf("which element want to search??\n");
    scanf("%d",&search_element);
    int found=linear_search(input,n,search_element);
    if(found!=-1)
    {
        printf("element found at %d position\n",found);
    }
    else
    {
        printf("element not found\n");
    }
    return 0;
}
