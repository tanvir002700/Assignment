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
    cout<<"enter number of input: "<<endl;
    int n;
    cin>>n;
    stringstream ss;
    ss<<n;
    string s=ss.str();
    cout<<s<<endl;
    string file_name="file"+s+".txt";
    fp=fopen(file_name.c_str(),"w");
    int mod=1e7+7;
    for(int i=0;i<n;i++)
    {
        int x=rand()%mod;
        fprintf(fp,"%d\n",x);
    }
    fclose(fp);
    return 0;
}
