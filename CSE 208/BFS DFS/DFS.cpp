/**
    Tanvir Hasan
    Uap, 31st Batch
    email: tanvir002700@gmail.com
**/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector< vector<int> >Graph;
bool visit[100000];
int dist[10000];
int parent[10000];
int last_node;
void dfs(int u)
{
    visit[u]=true;
    for(int i=0;i<Graph[u].size();i++)
    {
        int v=Graph[u][i];
        if(visit[v]==false)
        {
            parent[v]=u;
            last_node=v;
            dfs(v);
        }
    }
}
void path(int v)
{
    if(parent[v]==-1)
    {
        printf("%d",v);
        return;
    }
    path(parent[v]);
    printf(" -> %d",v);
}

int main()
{
    printf("Number of node: ");
    int N;
    scanf("%d",&N);
    Graph=vector< vector<int> >(N+1);
    printf("Number of Edges: ");
    int Edges;
    scanf("%d",&Edges);
    for(int i=0;i<Edges;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        Graph[u].pb(v);
        Graph[v].pb(u);
    }
    int u;
    printf("Enter starting node: ");
    scanf("%d",&u);
    memset(parent,-1,sizeof(parent));
    dfs(u);
    path(last_node);
    return 0;
}
