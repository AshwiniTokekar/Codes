#include <iostream>
#include <vector>
//#include <cmath>
using namespace std;
int main()
{
	vector<int>x(4,0);
	vector<int> y(4,0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(n==1)
		cout<<"-1\n";
	else if(n==2)
	{
      if(x[0]!=x[1]&&y[0]!=y[1])
      {
      	int area=(x[1]-x[0])*(y[1]-y[0]);
      	if(area<0)
      		area*=-1;
      	cout<<area<<"\n";
      }
      else
      {
      	cout<<"-1\n";
      }
	}
	else if(n==3)
	{
		int i=0,j=0;
		for(;i<3;i++)
		{
			bool found=false;
			 for(j=i+1;j<3;j++)
			{
				if(x[i]!=x[j]&&y[i]!=y[j])
				{
				//	cout<<"The diagonal elements\n";
				//	cout<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<"\n";
					found=true;
					break;
					
				}
			}
			if(found)
				break;
		}
		//cout<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<"\n";
		int area=(x[j]-x[i])*(y[j]-y[i]);
      	if(area<0)
      		area*=-1;
      	cout<<area<<"\n";
	}
	else
	{
		int i=0,j=0;
		for(;i<=3;i++)
		{
			bool found=false;
			for(j=i+1;j<=3;j++)
			{
				
				if(x[i]!=x[j]&&y[i]!=y[j])
				{
					found=true;
					break;
					
				}
			}
			if(found)
				break;
		}	
		int area=(x[j]-x[i])*(y[j]-y[i]);
      	if(area<0)
      		area*=-1;
      	cout<<area<<"\n";
	}

}