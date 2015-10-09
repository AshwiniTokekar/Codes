nclude<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
  int v,dist;
};
int bfs(vector<int>graph,int N)
{

  vector<bool>visited(101,false);
  //int moves=0;
  queue<node>q;
  node n={1,0},temp;
  visited[0]=true;
  q.push(n);
  while(!q.empty())
  {
     // cout<<"in while ";
      n=q.front();
      q.pop();
   //   cout<<"in while "<<n.v<<"\n";  
     // int val=n.v;
      if(n.v==N)
        break;
      for(int j=n.v+1;j<=(n.v+6)&&j<=N;j++)
       {
              if(!visited[j])
               {
                          temp.dist=n.dist+1;
                     //     cout<<temp.dist<<"\n";
                          visited[j]=true;
                          if(graph[j]!=-1)
                          {
                                         
                                       temp.v=graph[j];
                                         q.push(temp);
                                       //temp.v=j;  
                                     } 
                          else
                             temp.v=j;
                          q.push(temp);
                        }
           }
     
    }
    if(q.empty()&&n.v!=N)
         return -1;
return n.dist;
}
int main()
{
  int T,N,M,x,y;  
  cin>>T;
  for(int i=0;i<T;i++)
   {
          vector<int>graph(101,-1);
          cin>>M;
          for(int j=0;j<M;j++)
             { 
                          cin>>x>>y;
                          graph[x]=y;
                       //   cout<<graph[x]<<" ";
                       }
         
         cin>>M;
          for(int j=0;j<M;j++)
             { 
                          cin>>x>>y;
                          graph[x]=y;
                         // cout<<graph[x]<<" ";
                       }
        // cout<<"\n";
         int ans=bfs(graph,100);
         cout<<ans<<"\n";
      }
  return 0;
}
