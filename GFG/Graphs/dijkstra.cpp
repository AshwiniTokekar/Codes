#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
using namespace std;
struct node
{
  int end,weight;
};
bool compare(node a,node b)
{
  if(a.weight>b.weight)
      return true;
  return false;
}
class Graph
{
  int V;
  vector<list<node> >g;

  public:
   Graph(int nov);
   void addedge(int v,int u,int w);
   vector<int> dijkstra(int src);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<V;i++)
    g.push_back(list<node>());
}
void Graph::addedge(int u,int v,int w)
{
  node n;
  n.end=v;
  n.weight=w;
  g[u].push_back(n);
  n.end=u;
  g[v].push_back(n);
}
//nodex=heap array
//dist=final array
vector<int> Graph::dijkstra(int src)
{
   vector<bool>visited(V,false);
   vector<node>nodex(V);
   for(int i=0;i<V;i++)
   {
     nodex[i].end=i;
     nodex[i].weight=INT_MAX;
   }
   vector<int>dist(V,INT_MAX);
//   cout<<nodex.size()<<"\n";
  nodex[src].weight=0;
  dist[src]=0;
  make_heap(nodex.begin(),nodex.end(),compare);
  for(int i=0;i<V;i++)
  {
    pop_heap(nodex.begin(),nodex.end(),compare);
    //nodex.pop_back();
    int cur=nodex.size()-1;
    dist[nodex[cur].end]=nodex[cur].weight;
    //int u=nodex[cur];
    list<node>::iterator it;
    for(it=g[nodex[cur].end].begin();it!=g[nodex[cur].end].end();it++)
    {
     node v=*it;
    int j;
    for(j=0;j<V;j++)
    {
      if(nodex[j].end==v.end)
           {
             break;
           }
    }
      
      if(!visited[v.end]&&nodex[cur].weight!=INT_MAX&&nodex[j].weight>nodex[cur].weight+v.weight)
                          nodex[j].weight=nodex[cur].weight+v.weight;
    }
    nodex.pop_back();
    make_heap(nodex.begin(),nodex.end(),compare);
  }
  return dist;
}
int main()
{
  Graph g(9);
  g.addedge(0,1,4);
  g.addedge(0,7,8);
  g.addedge(1,2,8);
  g.addedge(1,7,11);
  g.addedge(2,3,7);
  g.addedge(2,8,2);
  g.addedge(2,5,4);
  g.addedge(3,4,9);
  g.addedge(3,5,14);
  g.addedge(4,5,10);
  g.addedge(5,6,2);
  g.addedge(6,7,1);
  g.addedge(6,8,6);
  g.addedge(7,8,7);
  vector<int>ans=g.dijkstra(0);
  cout<<ans.size()<<"\n";
  for(int i=0;i<ans.size();i++)
  {
    cout<<i<<" "<<ans[i]<<"\n";
  }  
  return 0;
}
