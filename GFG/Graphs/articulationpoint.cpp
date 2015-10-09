#include <iostream>
#include <climits>
#include <vector>
#include <list>
using namespace std;
class Graph
{
  int V;
  vector<list<int> >g;
  void aputil(int u,vector<bool>&visited,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&ap);
  public:
   Graph(int nov);
   void addedge(int u,int v);
   void findarticulationpoints();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<nov;i++)
    g.push_back(list<int>());
}
void Graph::addedge(int u,int v)
{
  g[u].push_back(v);
  g[v].push_back(u);
}
void Graph:: aputil(int u,vector<bool>&visited,vector<int>&disc,vector<int>&low,vector<int>&parent,vector<bool>&ap)
{
//  cout<<u<<" ";
  int children=0;
  static int time=0;
  visited[u]=true;
  time++;
  disc[u]=time;
  low[u]=time;
  list<int>:: iterator i;
  for(i=g[u].begin();i!=g[u].end();i++)
  {
    int v =*i;
    if(!visited[v])
    {
      children++;
      parent[v]=u;
      aputil(v,visited,disc,low,parent,ap);
      low[u]=(low[u]<low[v]?low[u]:low[v]);
      if(parent[u]==-1&&children>=2)
      {
       // cout<<u<<" ";
        ap[u]=true;
      }
      if(parent[u]!=-1&&low[v]>=disc[u])
      {
        //cout<<u<<" ";
        ap[u]=true;
      }
    }
    else if(v!=parent[u])
    {
      low[u]=(low[u]<low[v]?low[u]:low[v]);
    }

  }
}
void Graph::findarticulationpoints()
{
    vector<bool>visited(V+1,false);
    vector<int>disc(V+1,0);
    vector<int>parent(V+1,-1);
    vector<bool>ap(V+1,false);
    vector<int>low(V+1,0);
    for(int i=0;i<V;i++)
      if(!visited[i])
         aputil(i,visited,disc,low,parent,ap);
    for(int i=0;i<V;i++)
      if(ap[i])
        cout<<i<<" ";
    cout<<"\n";
}
int main()
{
	 cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    g1.findarticulationpoints();
 
    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    g2.addedge(2, 3);
    g2.findarticulationpoints();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addedge(0, 1);
    g3.addedge(1, 2);
    g3.addedge(2, 0);
    g3.addedge(1, 3);
    g3.addedge(1, 4);
    g3.addedge(1, 6);
    g3.addedge(3, 5);
    g3.addedge(4, 5);
    g3.findarticulationpoints();

  return 0;
}
