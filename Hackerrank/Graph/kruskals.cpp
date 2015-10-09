#include<iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
struct edge
{
  int start,end,weight;
};
bool compare(edge a,edge b)
{
    if(a.weight==b.weight)
        {
          return (a.start+a.end+a.weight)<(b.start+b.end+b.weight);
    }
   return a.weight<b.weight;
}
class Graph
{
  int V;
  int noe;
  vector<edge> g;
  int getparent(int n,vector<int>parent);
  public:
    int kruskals(int src);
    void addedge(int u,int v,int w);
    Graph(int nov,int e);
};
int Graph::getparent(int n,vector<int>parent)
{
  int temp=n;
    while(n!=parent[n])
      n=parent[n];
    parent[temp]=n;
    return n;
}
Graph::Graph(int nov,int e)
{
  V=nov;
  noe=e;  
}
void Graph::addedge(int u,int v,int w)
{
  edge n;
  n.start=u;
  n.end=v;
  n.weight=w;
  g.push_back(n);
 // noe++;
}
int Graph::kruskals(int src)
{
  //  cout<<"sorting started\n";
 sort(g.begin(),g.end(),compare);
//  for(int i=0;i<noe;i++)
  //  cout<<g[i].start<<" "<<g[i].end<<" "<<g[i].weight<<"\n";
  int ans=0;
  vector<int>parent(V+1);
  vector<int>rank(V+1,1);
  for(int i=0;i<=V;i++)
    parent[i]=i;
  int sel=0;
  for(int i=0;i<V-1&&sel<g.size();sel++)
  {
   
     edge e=g[sel];
     int x=getparent(e.start,parent);
     int y=getparent(e.end,parent);
     if(x!=y)
     {
    //   cout<<e.start<<" "<<e.end<<" "<<e.weight<<"\n";
       ans+=e.weight;
       if(rank[e.start]>rank[e.end])
           parent[y]=x;
       else if(rank[e.end]>rank[e.start])
           parent[x]=y;
       else
       {
         parent[y]=x;
         rank[x]++;
       }

       i++;
     }
     //sel++;
  }
  return ans;

  return ans;
}
int main()
{
   long long int ans=0;
    int n,m,u,v,w,src;
    cin>>n>>m;
  Graph g(n,m);
  for(int i=0;i<m;i++)
   {
      cin>>u>>v>>w;
      g.addedge(u,v,w);  
  //    cout<<"taking input\n";
  }
   cin>>src; 
 //   cout<<"input recieved\n";
  ans=g.kruskals(src);
  cout<<ans<<"\n";  
  return 0;
}
