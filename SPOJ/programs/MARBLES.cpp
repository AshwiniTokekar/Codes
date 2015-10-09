# include <iostream>
using namespace std;
int main()
{
	int noc;
	unsigned long long int n,k,ans;
	cin>>noc;
	while(noc)
	{
	//	cout<<sizeof(unsigned long long int)<<"\n";
		noc--;
		cin>>n>>k;
		ans=1;
		if(n!=k)
		{
		  
          n--;
          k--;
        //  temp2=1;
          if(k>n/2)
          	k=n-k;
         for(unsigned long long int i=1;i<=k;i++)
         {
         	ans=ans*n;
         	ans=ans/(i);
         	n--;
         }
    
		}
		
        cout<<ans<<"\n";
	}
	return 0;
}