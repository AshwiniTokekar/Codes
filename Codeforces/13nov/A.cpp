#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;
int main()
{
	int64_t t,n;
	int64_t sum=0;
	cin>>t;
	while(t)
	{
		t--;
		cin>>n;
		sum=((n+1)*n)/2;
		//cout<<sum<<"\n";
		int64_t x=log2(n);
		//cout<<x<<"\n";
		int64_t diff= (pow(2,x+1)-1);
		sum=sum-(2*diff);
		cout<<sum<<"\n";
	}
}