#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long int n,temp,old;
	long long int ans=0;
	cin>>n;
	vector<long long int>inp;
	cin>>temp;
	inp.push_back(temp);
	old=temp;
	if(temp!=0)
		ans=abs(temp);
	//vector<int>oup;
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		inp.push_back(temp);
		if(old!=temp)
		{
			ans+=abs(temp-old);
			old=temp;
		}
	}
	cout<<ans<<"\n";
	return 0;
}