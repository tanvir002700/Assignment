#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct info
{
    int v,w;
    info(int v=0,int w=0):v(v),w(w){};
    bool operator<(const info &a)const{
        return w>a.w;
    }
};
typedef vector< vector<info> > vector2D;
typedef vector<int> vint;

map<string,int>City;
vector<string>City2;
vector2D Graph;
vint Dist,parent;

int GreedyBestFirstSearch(int source,int des)
{
    Dist=vint(Graph.size()+1,(1<<28));
    parent=vint(Graph.size()+1,-1);
    priority_queue<info>Q;
    Dist[source]=0;
    Q.push(info(source,0));
    while(!Q.empty())
    {
        info u=Q.top();
        if(u.v==des) return u.w;
        Q.pop();
        for(int i=0;i<Graph[u.v].size();i++)
        {
            info v=Graph[u.v][i];
            int uTOv=u.w+v.w;
            if(Dist[v.v]>uTOv)
            {
                parent[v.v]=u.v;
                Q.push(info(v.v,uTOv));
                Dist[v.v]=uTOv;
            }
        }
    }
    return -1;
}

void printPath(int u)
{
    if(parent[u]==-1)
    {
        cout<<City2[u]<<" ";
        return;
    }
    printPath(parent[u]);
    cout<<City2[u]<<" ";
}

int main()
{
    freopen("input.txt","r",stdin);
    int N,Edge;
    cin>>N>>Edge;
    int cnt=0;
    Graph=vector2D(N+1);
    for(int i=0;i<Edge;i++)
    {
        string name1,name2;
        int w;
        cin>>name1>>name2>>w;
        if(City.find(name1)==City.end())City[name1]=cnt++;
        if(City.find(name2)==City.end())City[name2]=cnt++;
        int x=City[name1];
        int y=City[name2];
        Graph[x].pb(info(y,w));
        Graph[y].pb(info(x,w));
    }
    City2=vector<string>(City.size()+1);
    for(auto x:City)
    {
        City2[x.second]=x.first;
    }

    string source,destination;
    cin>>source>>destination;
    int s=GreedyBestFirstSearch(City[source],City[destination]);
    if(s==-1)
    {
        cout<<"Can't reach\n";
        return 0;
    }
    cout<<s<<endl;
    printPath(City[destination]);
    return 0;
}
