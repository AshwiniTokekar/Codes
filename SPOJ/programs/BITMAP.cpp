# include <iostream>
# include <queue>
# include <utility>
using namespace std;
char arr[185][185];
int dist[185][185];
int visited[185][185];
int row[4]={-1,0,0,1};
int col[4]={0,-1,1,0};
void initialize(int r,int c)
{
	for(int i=0;i<=r;i++)
		for(int j=0;j<=c;j++)
		{
			dist[i][j]=32767;
			arr[i][j]='\0';
			visited[i][j]=0;
		}
}
queue <pair<int ,int > > bfsqueue;

void bfs(int r,int c)
{
	int x1,y1;
	while(!bfsqueue.empty())
	{
       pair <int,int> node = bfsqueue.front();
       bfsqueue.pop();
       for(int k=0;k<=4;k++)
    	{
    		int d=0;
    		x1=node.first+row[k];
    		y1=node.second+col[k];
    		if((x1>0)&&(y1>0)&&(y1<=c)&&(x1<=r)&&visited[x1][y1]==0)
    		{
    		  
    			if(row[k]==-1||row[k]==1)
    				d++;
                if(col[k]==-1||col[k]==1)
                    d++; 
                dist[x1][y1]=d+dist[node.first][node.second];
                bfsqueue.push(make_pair(x1,y1));
                visited[x1][y1]=1;

    			
    		}
    	}
       
	}
 
}    	

int main() 
{
	int noc,r,c;
	cin>>noc;
    while(noc)
    {
    	noc--;
    	cin>>r>>c;
    	initialize(r,c);
    	for(int i=1;i<=r;i++)
    		for(int j=1;j<=c;j++)
    		{
    			cin>>arr[i][j];
    			if(arr[i][j]=='1')
    				{
    					dist[i][j]=0;
    					bfsqueue.push(make_pair(i,j));
    					visited[i][j]=1;
    				}	
    		}
       bfs(r,c);
        for(int i=1;i<=r;i++)
         {
         	for(int j=1;j<=c;j++)
    		     cout<<dist[i][j]<<" ";
    		cout<<"\n"; 
         }
    }
	return 0;
}