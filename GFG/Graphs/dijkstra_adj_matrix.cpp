#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;
vector<vector<int> > g;
int minkey(vector<int>key,vector<bool>myset)
{ 
   int index=0,min=INT_MAX;
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
vector<int> dijkstra(int V,int src)
{
  vector<int>dist(V,INT_MAX);
  vector<bool>myset(V,false);
  dist[src]=0;
  int count=0;
  while(count<V)
  {
    int u=minkey(dist,myset);
    myset[u]=true;
    count++;
    for(int i=0;i<V;i++)
    {
      if(!myset[i]&&g[u][i]&&dist[u]+g[u][i]<dist[i])
            dist[i]=dist[u]+g[u][i];
    }
  }
  return dist;
}
int main()
{
  g= { {0, 4, 0, 0, 0, 0, 0, 8, 0},
       {4, 0, 8, 0, 0, 0, 0, 11, 0},
       {0, 8, 0, 7, 0, 4, 0, 0, 2},
       {0, 0, 7, 0, 9, 14, 0, 0, 0},
       {0, 0, 0, 9, 0, 10, 0, 0, 0},
       {0, 0, 4, 0, 10, 0, 2, 0, 0},
       {0, 0, 0, 14, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7},{0, 0, 2, 0, 0, 0, 6, 7, 0}};

 vector<int>ans=dijkstra(9,0);
 for(int i=0;i<9;i++)
   cout<<i<<" "<<ans[i]<<"\n";
  return 0;
}
