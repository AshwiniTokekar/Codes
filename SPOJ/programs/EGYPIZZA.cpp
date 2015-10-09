# include <iostream>
using namespace std;
const string q="1/4",h="1/2",t="3/4";
//enum parts { q="1/4"} ;   //  ,1/2,3/4 };
int main()
{
	int nof;
	int qua=0,half=0,thf=0,temp=0;
	int ans=1;
	string part;
	cin>>nof;
	for(int i=0;i<nof;i++)
	{
		cin>>part;
		if(part==q)
			 qua++;
		else if(part==h)
		     half++;
		else if(part==t)
		      thf++;     	
		
		
		

	}
	ans+=(half/2)+(half%2);
	//cout<<ans<<" ";
	ans+=thf;
	//cout<<ans<<" ";
	qua=qua-thf;
//	cout<<qua<<"\n";
	qua=qua-(half%2)*2;
	//cout<<qua<<"\n";
	if(qua>0&&qua%4!=0)
		ans++;//qua;
	if(qua>0)
        ans+=(qua/4);
	cout<<ans<<"\n";
	return 0;
}