# include <iostream>
using namespace std;
long long int C[100000];
int main()
{
	int noc;
	unsigned long long int n,k,ans,temp1,temp2,num,deno;
	cin>>noc;
	while(noc)
	{
		noc--;
		cin>>n>>k;
		ans=1;
		num=1;
		deno=1;
		if(n!=k)
		{
		  n--;
		  k--;
		  C[0]=1;
		  for(int i=1;i<=n;i++)
		  {
		  	int j=i<k?i:k;
		  	for(;j>0;j--)
		  	{
		  		C[j]=C[j]+C[j-1];
		  	}
		  }
		  ans=C[k];
          
		}
		
        cout<<ans<<"\n";
	}
	return 0;
}