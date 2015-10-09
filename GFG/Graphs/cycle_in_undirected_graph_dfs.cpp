#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
class Graph
{
   int V;
   vector<list<int> >adjlist;
  public:
   Graph(int nov);
   void addedge(int v,int w);
   bool iscycle();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=V;i++)
    adjlist.push_back(list<int>());
}
void Graph::addedge(int v,int w)
{
   adjlist[v].push_back(w);
   adjlist[w].push_back(v);
}
bool Graph::iscycle()
{
   vector<int>visited(V+1,-1);
   stack<int> st;
   list<int>::iterator i;
   st.push(1);
   visited[1]=1;
   while(!st.empty())
   {
      int temp=st.top();
      st.pop();
      for(i=adjlist[temp].begin();i!=adjlist[temp].end();i++)
            {
              if(visited[*i]==-1)
              {//Node is not visited
                visited[*i]=temp; 
                st.push(*i);   
              }
              else if(visited[*i]!=*i) 
              { //Node is not a parent of itself and visted by some other node
                  //cout<<visited[*i]<<" "<<*i<<"\n";
                  return true;
              }
            }
   }
   return false;
}
int main()
{
  Graph g1(5);
  g1.addedge(1, 0);
  g1.addedge(0, 2);
  g1.addedge(2, 0);
  g1.addedge(0, 3);
  g1.addedge(3, 4);
  g1.iscycle()? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";
                           
  Graph g2(3);
  g2.addedge(0, 1);
  g2.addedge(1, 2);
  g2.iscycle()? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";
  return 0;
}

