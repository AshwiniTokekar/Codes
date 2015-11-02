#include<iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
class Graph
{
  int V;
  vector<list<int> >g;
  bool DFS();
  public:
    void addedge(int u,int v);
    int iseulerian();
    Graph(int nov);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<V;i++)
    g.push_back(list<int>());
}
void Graph::addedge(int u,int v)
{
  g[u].push_back(v);
  g[v].push_back(u);
}

int Graph::iseulerian()
{ 
  if(!DFS())
      return 0;
   int odd=0;
   for(int i=0;i<V;i++)
     if(g[i].size()&1)
       odd++;
   if(odd>2)
      return 0;
   return (odd==0?2:1);
}

bool Graph::DFS()
{
  int v=V;
  vector <bool> visited(V+1,false);
  for(int j=0;j<V;j++)
  {
    if(g[j].size()!=0)
    {
       v=j;
       break;
    }
  }
  if(v==V)
    return true;
  list <int>::iterator i;
  stack<int> st;
  st.push(v);
  while(!st.empty())
  {
     int temp=st.top();
     st.pop();
     visited[temp]=true;
     for(i=g[temp].begin();i!=g[temp].end();i++)
          if(!visited[*i])
            st.push(*i);
  }
  for(int i=0;i<V;i++)
    if(!visited[i]&&g[i].size()>0)
        return false;
  return true;
}
void test(Graph g)
{
  int res=g.iseulerian();
  if(res==0)
    cout<<"Graph is not Eulerian\n";
  else if(res==1)
    cout<<"Graph has a Euler Path\n";
  else
    cout<<"Graph has a Euler Cycle\n";
}
int main()
{
  Graph g1(5);
    g1.addedge(1, 0);
    g1.addedge(0, 2);
    g1.addedge(2, 1);
    g1.addedge(0, 3);
    g1.addedge(3, 4);
    test(g1);
 
    Graph g2(5);
    g2.addedge(1, 0);
    g2.addedge(0, 2);
    g2.addedge(2, 1);
    g2.addedge(0, 3);
    g2.addedge(3, 4);
    g2.addedge(4, 0);
    test(g2);
 
    Graph g3(5);
    g3.addedge(1, 0);
    g3.addedge(0, 2);
    g3.addedge(2, 1);
    g3.addedge(0, 3);
    g3.addedge(3, 4);
    g3.addedge(1, 3);
    test(g3);
 
    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addedge(0, 1);
    g4.addedge(1, 2);
    g4.addedge(2, 0);
    test(g4);
 
    // Let us create a graph with all veritces
    // with zero degree
    Graph g5(3);
    test(g5);	
  return 0;
}
