# include <cstdio>
#include <iostream>
using namespace std;
int party[101][501],fun[101],cost[101];
//party=dp table array
//fun=fun value
//cost =cost value
//Applying standard 0-1knapsack sol
//to findmax money spent find i where total fun is just less than maxfun
void initialize()
{
	for(int i=0;i<=100;i++)
		{
		  fun[i]=0;
		  cost[i]=0;	
		  for(int j=0;j<=500;j++)
			party[i][j]=0;
	    }
}
int max (int a,int b) { return a>b ? a:b;}
int main()
{
    int spend,nop,finalcost;
    scanf("%d%d",&spend,&nop);
    while(spend!=0&&nop!=0)
    {
    	initialize();
    //	cout<<nop<<" "<<spend<<"\n";
    	for(int i=1;i<=nop;i++)
    	cin>>cost[i]>>fun[i];
    for(int i=0;i<=nop;i++)
    	for(int j=0;j<=spend;j++)
    	{
    		if(i==0||j==0)
    			 {
    			 	party[i][j]=0;
    			 	sele[i][j]=0;
    			 }	
    		else if(cost[i]<=j)
    		{
    			int t=max(party[i-1][j],fun[i]+party[i-1][j-cost[i]]);
                 party[i][j]=t;
                 
                 if(party[i][j]==fun[i]+party[i-1][j-cost[i]])
                 	sele[i][j]=1;
                 else
                 	sele[i][j]=0;
                 
    		}	
    		else
    		{
    			party[i][j]=party[i-1][j];
    			sele[i][j]=0;
    		}
    	}
    /*	 for(int i=0;i<=nop;i++)
    	 {
    	 	for(int j=0;j<=spend;j++)
    	       cout<<party[i][j]<<" ";
    	   cout<<"\n";
    	 }
    	*/
    int temp=spend;
    finalcost=0;	
   /* for(int i=nop;i>=1&&temp>0;i--)
    {
    	/*if(sele[i][temp]==1)
    	{
  //   	  cout<<i<<' '<<cost[i]<<" "<<fun[i]<<"\n";	
          finalcost+=cost[i];
          temp-=cost[i];
    	}
          if(party[i][j])
    }	*/
    int i=spend;      	
    for(;i>0;i--)
    {
    	if(party[nop][i]<party[nop][spend])
    		break;

    }	
    cout<<i+1<<" "<<party[nop][spend]<<"\n";	
  //  cout<<temp<<"\n";
  //  cin>>spend>>nop;
    scanf("%d%d",&spend,&nop);
  //  cout<<spend<<" "<<nop<<"\n";
    if(spend==0)
    	break;
    }
    

}