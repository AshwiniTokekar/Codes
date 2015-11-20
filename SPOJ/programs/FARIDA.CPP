#include <cstdio>
#include <vector>
using namespace std;
long long int getmaxsum(vector<long int>&arr)
{
	int len=arr.size()-1;
	long long int incl=arr[0],excl=0,excl_new;
	for(int i=1;i<len;i++)
	{
		excl_new=incl>excl?incl:excl;
		incl=excl+arr[i];
		excl=excl_new;
	}
	return(incl>excl?incl:excl);
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
	//	t--;
		scanf("%d",&n);
		vector<long int>arr(n+1,0);
		for(int i=0;i<n;i++)
		{
			scanf("%ld",&arr[i]);
		}
		printf("Case %d: %lld\n",j,getmaxsum(arr));
	}
	return 0;
}