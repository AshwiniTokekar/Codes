#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
vector <int>visited(1000,0);
vector <int>dist(1000,-1);
vector<vector<int> >adjmat(1000,vector<int>(1000,-1));
void initialize()
    {
      for (int i=0;i<1000;i++)
          {
              visited[i]=-1;
              dist[i]=-1;
              for(int j=0;j<1000;j++)
                  adjmat[i][j]=-1;
      } 
}
void bfs(int S,int N)
    {
       int temp;
       queue<int>q;
       q.push(S);
       visited[S-1]=0;
       dist[S-1]=0;
       while(!q.empty())
           {
             temp=q.front();
             q.pop();
             for(int i=1;i<=N;i++)
                 {
                   if(visited[i-1]==-1&&adjmat[temp-1][i-1]==6&&temp!=i)
                       {
                         visited[i-1]=0;
                         q.push(i);
                         dist[i-1]=dist[temp-1]+6;
                       }
                 }
          }
    }
void printdistance(int S,int N)
    {
      for(int i=1;i<=N;i++)
          {
            if(i!=S)
                 cout<<dist[i-1]<<" ";
      }
    cout<<"\n";
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T,N,M,x,y,S;
    cin>>T;
    for(int i=0;i<T;i++)
        {
           initialize();
           cin>>N>>M;
           for(int j=0;j<M;j++)
               {
                 cin>>x>>y;
     //            cout<<adjmat[x-1][y-1]<<" ";
                 adjmat[x-1][y-1]=6;
                 adjmat[y-1][x-1]=6;
       //          cout<<adjmat[x-1][y-1]<<"\n";
               }
           cin>>S;  
          bfs(S,N);
          printdistance(S,N);
        }
    return 0;
}