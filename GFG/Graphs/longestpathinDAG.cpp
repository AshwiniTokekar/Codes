#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<stack>
using namespace std;
struct node
{
  int end,weight;
};
class Graph
{
   int V;
   vector<list<node> >adjlist;
  public:
   Graph(int nov);
   void addedge(int u,int v,int w);
   void topologicalsort(int s,vector<bool> visited,stack<int>&st);
   void getlongestpath(int s);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=nov;i++)
     adjlist.push_back(list<node>());
}
void Graph::addedge(int u,int v,int w)
{
  node n;
  n.end=v;
  n.weight=w;
  adjlist[u].push_back(n);
}
void Graph::topologicalsort(int s,vector<bool>visited,stack<int>&st)
{
  visited[s]=true;
  list<node>::iterator i;
  for(i=adjlist[s].begin();i!=adjlist[s].end();i++)
  {
     node n=*i;
     if(!visited[n.end])
         topologicalsort(n.end,visited,st);

  }
  st.push(s);
}
void Graph::getlongestpath(int s)
{
  stack<int>st;
  vector<bool>visited(V+1,false);
  vector<int>dist(V+1,INT_MIN);
  dist[s]=0;
  for(int i=0;i<=V;i++)
  {
    if(!visited[i])
         topologicalsort(i,visited,st);
  }
  while(!st.empty())
  {
    int temp=st.top();
    st.pop();
    list<node>::iterator i;
    if(dist[temp]!=INT_MIN)
    {
      for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
      {
        if(dist[i->end]<dist[temp]+i->weight)
          dist[i->end]=dist[temp]+i->weight;
      }
    }

  }
  for(int j=0;j<V;j++)
    (dist[j]==INT_MIN)? cout<<"INF ":cout<<dist[j]<<" ";
}
int main()
{
  Graph g(6);
  g.addedge(0, 1, 5);
  g.addedge(0, 2, 3);
  g.addedge(1, 3, 6);
  g.addedge(1, 2, 2);
  g.addedge(2, 4, 4);
  g.addedge(2, 5, 2);
  g.addedge(2, 3, 7);
  g.addedge(3, 5, 1);
  g.addedge(3, 4, -1);
  g.addedge(4, 5, -2);
                                           
  int s = 1;
  cout << "Following are longest distances from source vertex " << s <<" \n";
  g.getlongestpath(s);
  cout<<"\n";                                                     
  return 0;
}
