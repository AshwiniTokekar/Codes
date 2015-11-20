#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int nof;
	string inp;
	float sum=1;
	cin>>nof;
	for(int i=0;i<nof;i++)
	{
		cin>>inp;
		if(inp.compare("1/2")==0)
		{
			sum+=0.5;
		}
		else if(inp.compare("3/4")==0)
		{
			sum+=0.75;
		}
		else
		{
			sum+=.25;
		}
	}
	int ans=ceil(sum);
	cout<<ans<<"\n";
	return 0;
}