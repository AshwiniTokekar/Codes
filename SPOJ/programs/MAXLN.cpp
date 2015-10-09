# include <iostream>
# include <iomanip>
using namespace std;
int main()
{
	int noc,i=1;
	long long int num;
	double ans;
	cin>>noc;
	while(i<=noc)
	{
		
		cin>>num;
		ans=(16*num*num)+1;
		ans/=4;
		cout<<"Case "<<i<<": "<<fixed<<setprecision(2)<<ans<<"\n";
		i++;
	}
	return 0;
}