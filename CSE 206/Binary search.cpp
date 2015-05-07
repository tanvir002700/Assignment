/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
int Binary_search(int *a,int low,int high,int Search_element)
{
   while(low<=high)
   {
       int mid=(low+high)/2;
       if(a[mid]==Search_element)
       {
           return mid;
       }
       if(Search_element>a[mid])
       {
           low=mid+1;
       }
       else
       {
           high=mid-1;
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
    int found=Binary_search(input,0,n-1,search_element);
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
