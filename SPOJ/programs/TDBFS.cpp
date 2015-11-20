#include <cstdio>
#include <climits>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Graph
{
  int V;
  vector<vector<int> >g;
  public:
   Graph(int nov);
   void addedge(int u,int v);
   void DFS(int u);
   void BFS(int u);
};

Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=nov;i++)
    g.push_back(vector<int>(nov,0));
}
void Graph::addedge(int u,int v)
{
  g[u].push_back(v);
 // g[v].push_back(u);
}
void Graph::DFS(int u)
{
  vector<bool>visited(V+1,false);
  stack<int> st;
  st.push(u);
  while(!st.empty())
  {
    int temp=st.top();
    printf("%d ",temp);
    st.pop();
    visited[temp]=true;
    for(i=1;i<=V;i++)
      if(!visited[*i]&&g[i]!=0)
        st.push(*i);
  }
  printf("\n");
}
void Graph::BFS(int u)
{
   vector<bool>visited(V+1,false);
   queue<int> q;
   q.push(u);
   while(!q.empty())
   {
        int temp=q.front();
        printf("%d ",temp);
        q.pop();
        visited[temp]=true;
        for(i=g[temp].begin();i!=g[temp].end();i++)
          if(!visited[*i])
            q.push(*i);
   }
   printf("\n");
}
int main()
{
  int k=0;
  int noc,nov,u,v,m;
  int ver,bod;
  scanf("%d",&noc);
  while(noc)
  {
    k++;
    noc--;
    scanf("%d",&nov);
    Graph g(nov);
    for(int i=0;i<nov;i++)
    {
        scanf("%d %d",&u,&m);
        for(int j=0;j<m;j++)
        {

          scanf("%d",&v);
     //     printf("%d ",v);
          g.addedge(u,v);
        }
    }
   printf("graph %d\n",k);
   scanf("%d %d",&ver,&bod); 
   while(ver!=0)
   {
     printf("%d %d\n",ver,bod);
     if(bod==0)
       g.DFS(ver);
     else
       g.BFS(ver);
     scanf("%d %d",&ver,&bod); 
   }
  }
  return 0;
}
