# include <iostream>
using namespace std;
int main()
{
	long long int num,ans;
     int noc;
     cin>>noc;
     while(noc)
     {
     	noc--;
     	cin>>num;
     	ans=(2*num*num*num)+(5*num*num)+(2*num);
        if(num%2==1)
            ans--;
        cout<<ans/8<<"\n";

     }
	return 0;
}