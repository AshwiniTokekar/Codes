#include <iostream>
#include <vector>
#include <list>
using namespace std;
class Graph
{
  int V;
  vector<list<int> >adjlist;
  bool isBCUtil(int v,vector<bool>& visited,vector<int>& disc,vector<int>& low,vector<int>& parent);
  public:
   Graph(int nov);
   void addedge(int u,int v);
   bool isBC();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<nov;i++)
    adjlist.push_back(list<int>());
}
void Graph::addedge(int u,int v)
{
  adjlist[u].push_back(v);
  adjlist[v].push_back(u);
}
bool Graph:: isBCUtil(int v,vector<bool>& visited,vector<int>& disc,vector<int>& low,vector<int>& parent)
{
  static int time=0;
  int children=0;
  visited[v]=true;
  time++;
  disc[v]=time;
  low[v]=time;
  list<int>::iterator i;

  for(i=adjlist[v].begin();i!=adjlist[v].end();i++)
  {
    int n=*i;
    if(!visited[n])
    {
      children++;
      parent[n]=v;
      if(isBCUtil(n,visited,disc,low,parent))
        return true;
      low[v]=low[v]<low[n]?low[v]:low[n];
      if(parent[v]==-1&&children>1)
        return true;
      if(parent[v]!=-1&&low[n]>=disc[v])
         return true;
    }
    else if(n!=parent[v])
      low[v]=low[v]<low[n]?low[v]:low[n];
  }

  return false;
}
bool Graph::isBC()
{
    vector<bool>visited(V+1,false);
    vector<int>disc(V+1,-1);
    vector<int>low(V+1,-1);
    vector<int>parent(V+1,-1);
    if(isBCUtil(0,visited,disc,low,parent))
      return false;
    for(int i=0;i<V;i++)
      if(!visited[i])
         return false;
    return true;
}
int main()
{
   Graph g1(2);
    g1.addedge(0, 1);
    g1.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g2(5);
    g2.addedge(1, 0);
    g2.addedge(0, 2);
    g2.addedge(2, 1);
    g2.addedge(0, 3);
    g2.addedge(3, 4);
    g2.addedge(2, 4);
    g2.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g3(3);
    g3.addedge(0, 1);
    g3.addedge(1, 2);
    g3.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g4(5);
    g4.addedge(1, 0);
    g4.addedge(0, 2);
    g4.addedge(2, 1);
    g4.addedge(0, 3);
    g4.addedge(3, 4);
    g4.isBC()? cout << "Yes\n" : cout << "No\n";
 
    Graph g5(3);
    g5.addedge(0, 1);
    g5.addedge(1, 2);
    g5.addedge(2, 0);
    g5.isBC()? cout << "Yes\n" : cout << "No\n";
  return 0;
}
