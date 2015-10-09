# include <iostream>
using namespace std;
int main()
 {
 	int noc;
 	int num;
 	long int temp;
 	long long int sum;
 	cin>>noc;
 	while(noc)
 	{
 		noc--;
 		sum=0;
 		cin>>num;
 		for(int i=0;i<num;i++)
 		{
            cin>>temp;
            sum=(sum+temp)%1000000007;
 		}
 		if(sum%num==0)
 			cout<<"YES\n";
 		else
 			cout<<"NO\n";

 	}
 	return 0;
 }