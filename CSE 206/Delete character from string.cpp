/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Delete(char *a,char c)
{
    char *ch;
    ch=(char*)calloc(sizeof(strlen(a)),sizeof(char));
    int index=0;
    for(int i=0;a[i];i++)
    {
        if(a[i]==c)continue;
        ch[index++]=a[i];
    }
    ch[index]=NULL;
    strcpy(a,ch);
}
int main()
{
    char ch[200],c;
    scanf(" %[^\n] %c",ch,&c);
    Delete(ch,c);
    printf("%s",ch);
    return 0;
}
