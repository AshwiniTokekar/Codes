#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph
{ 
   int V;
   vector<list<int> >adjlist;
  public:
   void addedge(int v,int u);
   bool isBipartite();
   Graph(int nov);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=V;i++)
    adjlist.push_back(list<int>());
}

void Graph::addedge(int v,int u)
{
  adjlist[v].push_back(u);
  adjlist[u].push_back(v);
}
bool Graph::isBipartite()
{
  vector<int>color(V+1,-1);
  queue<int>q;
  list<int>::iterator i;
  q.push(1);
  color[1]=1;
  while(!q.empty())
  {
    int temp=q.front();
    q.pop();
    for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
    {
      
       if(color[*i]==-1&&color[temp]==1)
       {  color[*i]=2;
         q.push(*i);
       }
       else if(color[*i]==-1&&color[temp]==2)
       {    color[*i]=1;
            q.push(*i);
       }
       else if(color[*i]==color[temp])
            return false;
    }

  }
  return true;
}
int main()
{
  Graph g(4);
  g.addedge(0, 1);
  g.addedge(0, 2);
  g.addedge(1, 2);
//  g.addedge(2, 0);
  g.addedge(2, 3);
  g.addedge(3, 3);
  if(g.isBipartite())
      cout<<"Is bipartite\n";
  else
     cout<<"Not bipartite\n";  
  return 0;
}
