#include <iostream>
#include <algorithm>
using namespace std;
string inp;
void rotate(int l,int r,int k)
{

}
int main()
{
	int l,r,k,m,nos;
	
	cin>>inp;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r>>k;
		nos=k%(r-l+1);
		l--;
		r--;
		for(int j=0;j<nos;j++)
		   rotate(inp.begin()+l,inp.begin()+r,inp.begin()+r);
	}
	cout<<inp<<"\n";
}