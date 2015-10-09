#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Graph
{
  int V;
  vector<vector<int> >g;
  vector<vector <int> >dist;
  public:
   Graph(int nov);
   void addedge(int u,int v,int w);
   void floydwarshall();
   int getval(int u,int v);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=V;i++)
  {
    g.push_back(vector<int>(nov+1,INT_MAX));
    dist.push_back(vector<int>(nov+1,INT_MAX));
  }
  for(int i=0;i<=V;i++)
  {
    g[i][i]=0;
    dist[i][i]=0;
  }
}
void Graph::addedge(int u,int v,int w)
{
   g[u][v]=w;
   dist[u][v]=w;
}
int Graph::getval(int u,int v)
{
  if(dist[u][v]==INT_MAX)
      return -1;
  return dist[u][v];
}
void Graph::floydwarshall()
{
  for(int k=1;k<=V;k++)
    for(int i=1;i<=V;i++)
      for(int j=1;j<=V;j++)
      {
        if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j])
        {
          dist[i][j]=dist[i][k]+dist[k][j];
        }
      }
}
int main()
{
  int n,m,u,v,w,q;
  cin>>n>>m;
  Graph g(n);
  for(int i=0;i<m;i++)
  {
      cin>>u>>v>>w;
      g.addedge(u,v,w);
  }
  g.floydwarshall();
  cin>>q;  
  for(int i=0;i<q;i++)
  {
      cin>>u>>v;
      cout<<g.getval(u,v)<<"\n";
  }
  return 0;
}
