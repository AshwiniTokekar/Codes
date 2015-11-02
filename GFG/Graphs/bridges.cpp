#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
class Graph
{
  int V;
  vector<list <int> >adjlist;
  void bridgeutil(int u,vector<bool>&visited,vector<int>&disc,vector<int> &low,vector<int> &parent);
  public:
  Graph(int nov);
  void addedge(int u,int v);
  int bridges();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<V;i++)
    adjlist.push_back(list<int>());
}
void Graph::addedge(int u,int v)
{
  adjlist[u].push_back(v);
  adjlist[v].push_back(u);
}
void Graph::bridgeutil(int u,vector<bool>&visited,vector<int>&disc,vector<int> &low,vector<int> &parent)
{
	

  static int time=0;
  visited[u]=true;
  time++;
  disc[u]=time;
  low[u]=time;
  list<int>:: iterator i;
  for(i=adjlist[u].begin();i!=adjlist[u].end();i++)
  {
    int v =*i;
    if(!visited[v])
    {

      parent[v]=u;
      bridgeutil(v,visited,disc,low,parent);
      low[u]=(low[u]<low[v]?low[u]:low[v]);
      if(low[v]>disc[u])
        cout<<u<<" "<<v<<"\n";
    }
    else if(v!=parent[u])
    {
      low[u]=(low[u]<disc[v]?low[u]:disc[v]);
    }

  }
}
int Graph::bridges()
{
    vector<bool>visited(V+1,false);
    vector<int>disc(V+1,0);
    vector<int>parent(V+1,-1);
    
    vector<int>low(V+1,0);
    for(int i=0;i<V;i++)
      if(!visited[i])
         bridgeutil(i,visited,disc,low,parent);
    cout<<"\n";
}
int main()
{
	 // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    g1.bridges();
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addedge(0, 1);
    g2.addedge(1, 2);
    g2.addedge(2, 3);
    g2.bridges();
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addedge(0, 1);
    g3.addedge(1, 2);
    g3.addedge(2, 0);
    g3.addedge(1, 3);
    g3.addedge(1, 4);
    g3.addedge(1, 6);
    g3.addedge(3, 5);
    g3.addedge(4, 5);
    g3.bridges();
 
  return 0;
}
