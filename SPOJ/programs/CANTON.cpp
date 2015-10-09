# include <iostream>
# include <cmath>
using namespace std;
int main()
 {
 	int noc;
 	long long num;
 	long int x;
 	long long int total;
 	long long int numer,deno;
 	cin>>noc;
    while(noc)
    {
    	noc--;
    	cin>>num;
    	x=ceil((sqrt(8*num+1)-1)/2);
    	//cout<<(sqrt(8*num+1)-1)/2<<"\n"<<x<<"\n";
    	total=x*(x+1);
    	total/=2;
    	total-=x;
    	total=num-total;
    	total--;
    	if(x%2==0)
    	{
             deno=x;
             numer=1;
             while(total)
             {
             	deno--;
             	numer++;
             	total--;
             }
                
    	}
    	else
    	{
    		deno=1;
    		numer=x;
    		while(total)
    		{
    			deno++;
    			numer--;
    			total--;
    		}

    	}
    //	cout<<x<<"\n";
        cout<<"TERM "<<num<<" IS "<<numer<<"/"<<deno<<"\n";
    } 
 	return 0;
 }