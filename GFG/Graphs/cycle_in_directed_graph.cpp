//Cycle in undirected graph using DFS.
//DFS generates a tree.
#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;
class Graph
{
  
   int V;
   vector<list<int> >adjlist;
  public:
   Graph(int nov);
   void addedge(int u,int v);
   bool cycledetection();
};
Graph::Graph(int nov)
{
   V=nov;
   for(int i=0;i<=V;i++)
       adjlist.push_back(list<int>());
}
void Graph::addedge(int u,int v)
{
  adjlist[u].push_back(v);
//  adjlist[v].push_back(u);
}
bool Graph::cycledetection()
{
  vector<bool>visited(V+1,false);
  stack<int>st;
  list<int>::iterator i;
  st.push(1);
  while(!st.empty())
  {
    int temp=st.top();
    st.pop();
    for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
    {
      if(visited[*i])
        return true;
      visited[*i]=true;
      st.push(*i);
    }
  }
  return false;
}
int main()
{
  Graph g(4);
  g.addedge(0, 1);
  g.addedge(0, 2);
  g.addedge(1, 2);
  g.addedge(2, 0);
  g.addedge(2, 3);
  g.addedge(3, 3);
  if(g.cycledetection())
     cout<<"Graph has cycle\n";
  else
    cout<<"Graph does not contain cycle\n";
  return 0;
}
