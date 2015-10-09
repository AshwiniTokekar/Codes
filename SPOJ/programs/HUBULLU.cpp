# include <iostream>
using namespace std;
int main()
{
	int noc,playerno;
	long long int num;
	cin>>noc;
	while(noc)
	{
		noc--;
		cin>>num>>playerno;
		if(playerno==1)
			cout<<"Pagfloyd wins.\n";
        else
        	cout<<"Airborne wins.\n";
	}
	return 0;
}