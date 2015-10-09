# include <iostream>
using namespace std;
int main()
 {
 	long long int a,d,n;
 	int noc;
 	long long int x; //3rd term
 	long long int y; //3last term
 	long long int z; //sum
 	cin>>noc;
 	while(noc)
 	{
 		noc--;
 		cin>>x>>y>>z;
 		n=(2*z)/(x+y);
 		d=(y-x)*(y+x);
 		d/=(2*z-5*(x+y));
 		a=x-2*d;
 		int i=0;
 		
 		cout<<n<<endl;
 		while(i<n)
 		{
 			cout<<a+i*d<<" ";
 			i++;
 		}
 		cout<<endl;

 	}
 	return 0;
 }