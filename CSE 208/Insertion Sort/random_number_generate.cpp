/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp;
    fp=fopen("rand.txt","w");
    for(int i=1;i<=10000;i++)
    {
        int n=rand()%5001;
        fprintf(fp,"%d\n",n);
    }
    fclose(fp);
    return 0;
}
