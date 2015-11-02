#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class Graph
    {
      int V;
      vector<list<int> >adjlist;
      vector<int>indegree,outdegree;
      Graph transpose();
      public:
       void addedge(int u,int v);
       Graph(int nov);
       Graph DFS(vector<bool>&visited);     
       bool isEulerian();
};
Graph::Graph(int nov)
    {
       V=nov;
       for(int i=0;i<=V;i++)
       {
           adjlist.push_back(list<int>());
//           cout<<adjlist[i].size()<<"\n";
           indegree.push_back(0);
           outdegree.push_back(0);
       }   
   }
Graph Graph::transpose()
    {
        list<int>::iterator it;
        Graph gr(V);
        cout<<"Creating transpose\n";
        for(int i=1;i<=V;i++)
            {
              cout<<"Step :"<<i<<"\n";
              for(it=adjlist[i].begin();it!=adjlist[i].end();it++)
                  {
                    int n=*it;
                    cout<<n<<" ";
                    gr.addedge(n,i);
                  }
        }
    return gr;
}
void Graph::addedge(int u,int v)
    {
    
      adjlist[u].push_back(v);
      indegree[v]++;
      outdegree[u]++;
      
   }
bool Graph::isEulerian()
    {
      bool issame=true;
       for(int i=1;i<=V;i++)
           {
             if(indegree[i]!=outdegree[i])
                 issame=false;
       }
     if(!issame)
         return false;
      vector<bool>visited(V+1,false);
    //   cout<<"phase1\n";       
     Graph gr= DFS(visited);
      for(int i=1;i<=V;i++)
          if(outdegree[i]>0&&!visited[i])
              return false;
      //cout<<"Checking transpose\n";      
           //=transpose();
      //cout<<"transpose arrived\n";
      vector<bool>visitedt(V+1,false);
      gr.DFS(visitedt);
      for(int i=1;i<=V;i++)
          if(outdegree[i]>0&&!visitedt[i])
              return false;
      if(!visitedt[V]||!visited[V])
          return false;      
      return true;    
   }

Graph Graph::DFS(vector<bool>&visited)
    {
       list <int>::iterator it;     
       stack<int>st;
       Graph gr(V);
       st.push(1);
       while(!st.empty())
           {
         //    vector<int>parent(V+1,0);
              int temp=st.top();
              st.pop();
              visited[temp]=true;   
              for(it=adjlist[temp].begin();it!=adjlist[temp].end();it++)
                  {
                    if(*it!=-1)
                        {
                         st.push(*it);
                         gr.addedge(*it,temp);
                         *it=-1;
                        }                   
                  }
           }
      return gr;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int noc,n,m,u,v;
    cin>>noc;
    while(noc)
        {
           noc--;
           cin>>n>>m;
           Graph g(n);
           for(int i=0;i<m;i++)
               {
                 cin>>u>>v;
                 g.addedge(u,v);
           }
 //       cout<<"Graph created\n";
        if(g.isEulerian())
            {
               cout<<"Go on get the Magical Lamp\n";
        }
        else
            cout<<"Danger!! Lucifer will trap you\n";
    }
    return 0;
}
