#include <iostream>
using namespace std;
int main()
{
	unsigned long long int num,noc,ans,i;
	cin>>noc;
	for(i=0;i<noc;i++)
	{
		cin>>num;
		/*if(num%2==1)
		{
			ans=(((num-1)*5)/2+1)*100+92;
		    cout<<ans<<"\n";
		}
		else
		{
		  ans=(((num-1)*5)/2+1)*100+42;
		    cout<<ans<<"\n";	
		}	*/
		ans=((num-1)/4)*1000;    
		switch((num-1)%4)
		{
			case 0: ans+=192;
			       break;
			case 1:ans+=442;
			       break;
			case 2:ans+=692;
			       break;
			case 3:ans+=942;
			       break;
		}    
		cout<<ans<<"\n";
	}
	return 0;
}