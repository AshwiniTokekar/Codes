# include <iostream>
using namespace std;
int main()
{
	long long int noc,num,ans=0;
	char c;
	cin>>noc;
	while(noc)
    {
    	noc--;
    	cin>>num;
        ans=num;
    	do
	    {
		cin>>c;
		if(c!='=')
		  cin>>num;
		switch(c)
		{
			case '+' : ans+=num;
			     break;
			case '-': ans-=num;
                 break;
            case '*': ans*=num;
                 break;
            case '/': ans/=num;
                 break;
            case '=': cout<<ans<<"\n";
		}
		
	    }while(c!='=');

    }
	
   return 0;
}