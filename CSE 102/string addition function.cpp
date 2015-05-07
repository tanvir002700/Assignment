/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<string.h>
#define max 10
char add(char n1[max],char n2[max])
{
    int i;
    char res[max]={0};
    strrev(n1);
    strrev(n2);
    for(i=0;i<max;i++)
    {
        if(n1[i]==NULL)
        {
            n1[i]=0;
        }
        else
        {
            n1[i]=n1[i]-48;
        }
        if(n2[i]==NULL)
        {
            n2[i]=0;
        }
        else
        {
            n2[i]=n2[i]-48;
        }
    }
    int hand=0;
    for(i=0;i<max;i++)
    {
        res[i]=(n1[i]+n2[i]+hand)%10+48;
        hand=(n1[i]+n2[i]+hand)/10;
    }
    for(i=max-1;i>=0;i--)
    {
        if(res[i]!='0')
        {
            res[i+1]=NULL;
            break;
        }
    }
    strrev(res);
    puts(res);
    return res[max];
}
