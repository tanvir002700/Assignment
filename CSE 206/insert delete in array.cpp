/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#define max 100
void Insert_in_middle(int *a,int pos,int n,int &total)
{
    int i;
    for(i=total-1;i>=pos;i--)
    {
        a[i+n]=a[i];
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[pos++]);
    }
    total+=n;
}
void insert_form_back(int *a,int &cnt,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[cnt++]);
    }
}
void print(int *a,int total)
{
    if(!total)
    {
        printf("Array is empty\n");
        return;
    }
    printf("current array element\n");
    for(int i=0;i<total;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void Delete(int *a,int pos,int how_many,int &total)
{
    for(int i=pos;i<total;i++)
    {
        a[i]=a[i+how_many];
    }
    total-=how_many;
}
void intro()
{
    printf("\n\npress 1 insert from back\n");
    printf("press 2 insert in middle\n");
    printf("press 3 delete\n");
    printf("press 4 to print current array\n\n");
}
int main()
{
    int arr[max];
    int dec;
    int cnt=0;
    int how_many;
    intro();
    while(scanf("%d",&dec)==1)
    {
        if(dec==1)
        {
            printf("how many element wants to add??\n");
            scanf("%d",&how_many);
            insert_form_back(arr,cnt,how_many);
        }
        else if(dec==2)
        {
            int pos;
            printf("how many element wants to add??\n");
            scanf("%d",&how_many);
            printf("which positio???\n");
            scanf("%d",&pos);
            Insert_in_middle(arr,pos,how_many,cnt);
        }
        else if(dec==3)
        {
            int pos;
            printf("how many element wants to delete\n");
            scanf("%d",&how_many);
            printf("which position???\n");
            scanf("%d",&pos);
            Delete(arr,pos,how_many,cnt);
        }
        else if(dec==4)
        {
            print(arr,cnt);
        }
        intro();
    }
    return 0;
}
