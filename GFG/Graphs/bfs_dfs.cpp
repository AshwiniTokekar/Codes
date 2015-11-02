#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
   int V;
   vector<list<int> > adjlist;
   public:
     Graph(int nov);
     void addEdge(int v,int w);
     void BFS(int s);
     void DFS(int s);
     //void dijkstra(int s);
     //void bellmanford();
     //void floydwarshall();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=V;i++)
    adjlist.push_back(list<int>());
} 

void Graph::addEdge(int v,int w)
{
   adjlist[v].push_back(w);
   adjlist[w].push_back(v);
}

void Graph::BFS(int s)
{
   vector<bool>visited(V+1,false);
   queue<int>q;
   list<int>::iterator i;
   q.push(s);
   visited[s]=true; 
   while(!q.empty())
   {
     int temp=q.front();
     q.pop();
     //Some required processing
     cout<<temp<<" ";
     for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
       {
           if(!visited[*i])
            {
              q.push(*i);
              visited[*i]=true;
            }
       }
   }
}
void Graph::DFS(int s)
{
   vector<bool>visited(V+1,false);
   stack<int>st;
   list<int>::iterator i;
   st.push(s);
   visited[s]=true;
   while(!st.empty())
   {
     int temp=st.top();
     st.pop();
     //Some required processing
     cout<<temp<<" ";
     for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
      {
         if(!visited[*i])
          {
             st.push(*i);
             visited[*i]=true;
          } 
      }
   }
}
int main()
{
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   cout<<"BFS -->2\n";
   g.BFS(2);
   cout<<"\n";
   cout<<"DFS -->2\n";
   g.DFS(2);
   cout<<"\n";
   return 0;
}
