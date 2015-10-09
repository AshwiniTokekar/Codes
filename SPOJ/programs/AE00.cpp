# include <iostream>
# include <cmath>
using namespace std;
int main()
 {
 	int num;
 	int ans;
 	cin>>num;
 	if(num==1)
 		cout<<"1\n";
 	else if(num<9)
    {
     ans=floor((3*num)/2);
     ans--;
     cout<<ans<<'\n';
    }
    else
    {
    	ans=0;
    	int i=floor(sqrt(num));

    	while(i>0)
    	{
    		ans+=floor((num/i))-(i-1);
    		i--;
    	}
    	cout<<ans<<"\n";
    }
 	return 0;
 }