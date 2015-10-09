#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
using namespace std;
vector< list<int> >graph(100010);
stack<int> st;
int visited[100010];
int distanceval[100010];
void initialize()
{
  for (int i=0;i<=100000;i++)
  {
    visited[i]=0;
    distanceval[i]=0;
    
  }
} 

int dfs(int ele,int &nod)
  {
    initialize();
    st.push(ele);
    int l=0;
    list <int> temp;
    list <int> :: iterator it;
    visited[ele]=1;
  while(!st.empty())
  {
     ele=st.top();
     st.pop();
     temp=graph[ele];
     for(it=temp.begin();it!=temp.end();it++)
        {
          if(visited[*it]==0)
          {
           st.push(*it);
           visited[*it]=1;
           distanceval[*it]=distanceval[ele]+1;
           if(l<distanceval[*it])
              {
                l=distanceval[*it]; 
                nod=*it;
              }
          }
          
        }
  }
     return l;
  }
void getlongestpath()
{

  int max2=0;
  int ele,ele1;
//  cout<<"in rfde\n";
  dfs(1,ele);
  max2=dfs(ele,ele1);
  cout<<max2<<endl;
 
}

int main()
{
  int u,v,non,j;
   cin>>non;
      for(j=1;j<non;j++)
      {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
      }
      getlongestpath();
      for(j=0;j<=non;j++)
        graph[j].clear();
               
  return 0;
}