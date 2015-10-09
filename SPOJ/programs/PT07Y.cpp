# include <iostream>
using namespace std;
int set[10010];
void initialize()
{
	for(int i=0;i<10010;i++)
		set[i]=i;
}
int main()
 {
 	int n,m;  // n=no of nodes , m= no of vertices 
 	int u,v,vset;
 	int flag=0;
 	cin>>n>>m;
 	initialize();
 	if(n==m+1)
 	{
 		while(m)
 		{
 			cin>>u>>v;
            if(set[u]==set[v]&&flag==0)
              flag=1;
            else
            {
               vset=set[v];
               for(int i=0;i<=n;i++)
               {
               	if(set[i]==vset)
               		set[i]=set[u];
               }
            }
            m--;
 		}
        if(flag==0)
        	cout<<"YES\n";
        else
        	cout<<"NO\n";

 	}
 	else
 	{
 		while(m)
 		{
 			cin>>u>>v;
            m--;
 		}
 		cout<<"NO\n";
 	}
 	return 0;
 }