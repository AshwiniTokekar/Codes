# include <iostream>
using namespace std;
int main()
{
	int noc;
	string base;
	long long int ex;
	int p,len;
    
    cin>>noc;
    while(noc)
    {
    	
    	noc--;
    	cin>>base;
    	len=base.length();
    	cin>>ex;
    	int t=base[len-1]-'0';
    //	cout<<t<<"\n";
    	ex=ex%4;
    	p=1;
    	if(t==0)
    		cout<<"0\n";
    	else
    	{
    		while(ex>0)
    	{
            p=p*t;
            ex--;
    	}
    	cout<<p%10<<"\n";
    	}
    	
    	
    }

}