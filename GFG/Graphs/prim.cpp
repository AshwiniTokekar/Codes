#include<iostream>
#include<vector>
#include <list>
#include<climits>
using namespace std;
struct node
{
  int weight;
  int end;
};
class Graph
{
   int V;
   vector<list<node> >g;
   int getminkey(vector<int> key,vector<bool>myset);
  public:
   Graph(int nov);
   void addedge(int u,int v,int w);
   vector<int> prim();
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<V;i++)
    g.push_back(list<node>());
}
int Graph::getminkey(vector<int>key,vector<bool>myset)
{
  int min=INT_MAX,index;
  for(int i=0;i<key.size();i++)
  {
    if(min>key[i]&&!myset[i])
    {
      min=key[i];
      index=i;
    }
      
  }
  return index;
}
void Graph::addedge(int u,int v,int w)
{
  node n;
  n.weight=w;
  n.end=v;
  g[u].push_back(n);
  n.end=u;
  g[v].push_back(n);
}
vector<int> Graph:: prim()
{
   vector<bool>myset(V,false);
   vector<int>key(V,INT_MAX);
   vector<int>parent(V,0);
   list<node>l;
   node n;
   list<node>::iterator i;
   int minkey;
   key[0]=0;
   int count=0; //Number of vertices in Set
   while(count<V)
   {
     minkey=getminkey(key,myset);
     myset[minkey]=true;
     count++;
     l=g[minkey];
     for(i=l.begin();i!=l.end();i++)
     {
         n=*i;
         if(n.weight<key[n.end]&&!myset[n.end])
         {
           key[n.end]=n.weight;
           parent[n.end]=minkey;         
         } 

     }
     
   }
   return parent; 
}
int main()
{
   Graph g(5);
   g.addedge(0,1,2);
   g.addedge(0,3,6);
   g.addedge(1,2,3);
   g.addedge(1,3,8);
   g.addedge(1,4,5);
   g.addedge(2,4,7);
   g.addedge(3,4,9);
 //  g.addedge();
 //  g.addedge();
   
   vector<int>ans=g.prim();
   for(int i=0;i<ans.size();i++)
     cout<<i<<"----"<<ans[i]<<"\n";
  return 0;
}
