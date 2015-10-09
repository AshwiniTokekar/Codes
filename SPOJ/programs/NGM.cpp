# include <iostream>
using namespace std;
int main()
{
	long long int num,y;
	cin>>num;
	if(num%10==0)
		cout<<"2\n";
	else
	{
		y=num/10;
		y*=10;
		y=num-y;
		cout<<"1\n"<<y<<"\n";
	}
	return 0;
}