#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define PI 3.14159265
using namespace std;
int main()
{
	int n,xtemp,ytemp;
	double dtemp;
	cin>>n;
	long int x[n],y[n];
	double dist [n];
	
	for(int i=0;i<n;i++)
	{
         cin>>x[i]>>y[i];
         //x.push_back(xtemp);
        // y.push_back(ytemp);
         dtemp=xtemp*xtemp+ytemp*ytemp;
         dtemp=sqrt(dtemp);
         dist[i]=dtemp;
	}
	double maxangle=INT_MAX;
	double angle;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
            angle=x[i]*x[j]+y[i]*y[j];
            angle/=dist[i];
            angle/=dist[j];
            angle=acos(angle);
            if(angle<0)
               angle*=-1;   
            angle=2*PI-angle<angle? 2*PI-angle:angle;
            if(angle<maxangle)
            {
            	maxangle=angle;
            	xtemp=i;
            	ytemp=j;
            }
		}
		cout<<xtemp+1<<" "<<ytemp+1<<"\n";
}