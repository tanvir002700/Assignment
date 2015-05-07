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
int bfs(int source,int destination)
{
    memset(visit,false,sizeof(visit));
    memset(parent,-1,sizeof(parent));
    dist[source]=0;
    parent[source]=-1;
    visit[source]=true;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            int v=Graph[u][i];
            if(visit[v]==false)
            {
                dist[v]=dist[u]+1;
                visit[v]=true;
                Q.push(v);
                parent[v]=u;
                if(v==destination)
                {
                    int temp=dist[v];
                    return temp;
                }
            }
        }
    }
    return -1;
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
    printf("Enter source & destination : ");
    int u,v;
    scanf("%d %d",&u,&v);
    int ans=bfs(u,v);
    if(ans!=-1)
    {
        printf("shortest path distance %d\n",ans);
        path(v);
    }
    else
    {
        printf("There is no path between %d & %d\n",u,v);
    }
    return 0;
}
