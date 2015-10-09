# include <iostream>
# include <cmath>
using namespace std;
int main()
{
	float g,b,ans;
	do
	{
       cin>>g>>b;
       if(g==-1&&b==-1)
       	break;
       if(g<b)
       {
       	  g=g+b;
       	  b=g-b;
       	  g=g-b;
       }
       ans=ceil(g/(b+1));
       cout<<ans<<"\n";
     
	}while(1);
	return 0;
}