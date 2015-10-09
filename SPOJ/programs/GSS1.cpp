#include <iostream>
#include <climits>
using namespace std;
int A[50000];
long long int aux[50000];
void initialize()
{
	for(int i=0;i<50000;i++)
		aux[i]=A[i];
}
long long int getmaxsum(int x,int y)
{
	 int i=x>0?x:1;
     long long int max=LLONG_MIN;
	 aux[0]=A[0]; 
     for(;i<y;i++)
     {
     	aux[i]=aux[i-1]+A[i];
     	if(aux[i]>max)
     		max=aux[i];
     }
} 
int main()
{
	int N,noq,x,y;
	long long int maxsum;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
    cin>>noq;
    for(int i=0;i<noq;i++)
    {
    	cin>>x>>y;
    	initialize();
    	maxsum=getmaxsum(x,y);
    	cout<<maxsum<<"\n";
    } 

	return 0;
}