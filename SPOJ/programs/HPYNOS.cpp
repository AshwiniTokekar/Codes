# include <iostream>
using namespace std;
int main()
{
	long long int num,temp;
	int nol=0,sum=0;
	cin>>num;
	sum=num;
	while(1)
	{
		nol++;
        temp=sum;
        sum=0;
        while(temp>0)
        {
        	int dig=(temp%10);
        	sum+=(dig*dig);
        	temp/=10;
        }
        if(sum==1)
        {
        	cout<<nol<<"\n";
        	break;
        }
        else if((sum<=9&&sum>1)||sum==0)
        {
        	cout<<"-1\n";
        	break;
        }
       // cout<<sum<<" "<<nol<<"\n";

	}
}