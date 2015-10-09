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
   vector<int> prim(int s);
};
Graph::Graph(int nov)
{
  V=nov;
  for(int i=0;i<=V;i++)
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
vector<int> Graph:: prim(int s)
{
   vector<bool>myset(V+1,false);
   vector<int>key(V+1,INT_MAX);
   vector<int>parent(V+1,0);
   list<node>l;
//    int ans=0;
   node n;
   list<node>::iterator i;
   int minkey;
   key[s]=0;
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
   return key; 
}
int main()
{
  int n,m,s,w,e,src;
    cin>>n>>m;
   // cout<<m<<"\n";
    Graph g(n);
    for(int i=0;i<m;i++)
      {
        cin>>s>>w>>e;
    //    cout<<"njbj "<<" "<<m<<" "<<i<<"\n";
        g.addedge(s,w,e);
      }
    cin>>src;
  //  cout<<"input \n";
   int sol=0;
   vector<int>ans=g.prim(s);
   for(int i=1;i<ans.size();i++)
       {
       sol+=ans[i];
      // cout<<i<<" "<<ans[i]<<"\n";
   }
            
    cout<<sol<<"\n";
  return 0;
}