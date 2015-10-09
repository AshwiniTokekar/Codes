# include <iostream>
using namespace std;
int main()
{
	unsigned long long int num;
	cin>>num;
	if((num!=0)&&((num&(~num+1))==num))
		cout<<"TAK\n";
	else
		cout<<"NIE\n";
	return 0;
}