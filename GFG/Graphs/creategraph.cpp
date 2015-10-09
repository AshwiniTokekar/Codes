#include <iostream>
using namespace std;
//Creating a graph using Adjacency List representation
struct adjlistnode
{
  int weight;
   int dest;
  adjlistnode *next;
};

struct adjlist
{
  adjlistnode *head;
};

struct Graph
{
  int nov;
  adjlist *array;
};
Graph* createGraph(int V)
{
  Graph *g=new Graph;
  g->nov=V;
  g->array=new adjlist[V];
  for(int i=0;i<V;i++)
  {
     g->array[i].head=NULL;
  }
  return g;
}
void addEdge(Graph *g,int src,int d,int w)
{
   adjlistnode *temp=new adjlistnode;
   temp->weight=w;
   temp->dest=d;
   temp->next=g->array[src].head;
   g->array[src].head=temp;
   
   adjlistnode *temp1=new adjlistnode;
   temp1->weight=w;
   temp1->dest=src;
   temp1->next=g->array[d].head;
   g->array[d].head=temp1;
   

}
void printGraph(Graph *g)
{
  for(int v=0;v<g->nov;v++)
    {
        adjlistnode *n=g->array[v].head;
        cout<<"Adjlist of vertex "<<v<<"\n\nhead";
        while(n)
         {
           cout<<"-->"<<n->dest;
           n=n->next;
         }
     cout<<"\n\n";
    }

}
int main()
{
  int v=5;
  Graph* graph = createGraph(v);
    addEdge(graph, 0, 1,1);
    addEdge(graph, 0, 4,2);
    addEdge(graph, 1, 2,3);
    addEdge(graph, 1, 3,4);
    addEdge(graph, 1, 4,1);
    addEdge(graph, 2, 3,1);
    addEdge(graph, 3, 4,1);
  printGraph(graph);
 return 0;
}
