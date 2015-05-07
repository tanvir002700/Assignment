/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
int row[101],col[101];
int dp[101][101];
int dir[101][101];
int solve(int l,int r)
{
    if(l>=r)return 0;
    int &ret=dp[l][r];
    if(ret!=-1)return ret;
    ret=(1<<29);
    for(int k=l;k<r;k++)
    {
        int val=solve(l,k)+solve(k+1,r)+row[l]*col[k]*col[r];
        if(ret>val)
        {
            ret=val;
            dir[l][r]=k;
        }
    }
    return ret;
}
void print(int l,int r)
{
    if(l>r)return;
    if(l==r)
    {
        printf("A%d",l);
        return;
    }
    printf("(");
    print(l,dir[l][r]);
    printf("x");
    print(dir[l][r]+1,r);
    printf(")");
}
int main()
{
    int number_of_matrix;
    cin>>number_of_matrix;
    for(int i=1;i<=number_of_matrix;i++)
    {
        cin>>row[i]>>col[i];
    }
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    cout<<solve(1,number_of_matrix)<<endl;
    print(1,number_of_matrix);
    return 0;
}
