#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<int>parent;
int getparent(int v)
{
	int temp=v;
  while(parent[v]!=v)
    v=parent[v];
  parent[temp]=v;
  return v;
}

int main()
{
  int V,N,x,y,px,py;
  bool iscycle=false;
  cin>>V>>N;
  for(int i=0;i<=V;i++)
    parent.push_back(i);
  for(int i=0;i<N;i++)
  {
    cin>>x>>y;
    px=getparent(x);
    py=getparent(y);
    if(px==py)
      iscycle=true;
    else
    {
      parent[y]=px;
      parent[py]=px;
    }
  }
  if(iscycle)
    cout<<"Cycle present\n";
  else
    cout<<"No cycle\n";
  return 0;
}
