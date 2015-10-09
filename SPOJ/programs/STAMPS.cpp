# include <iostream>
# include <algorithm>
using namespace std;
bool decreasing(int i,int j)
  {
  	return (i>j);
  }
int nos[1010];
int main()
 {
 	int noc,i,j;
 	int nof,nosr;
 	cin>>noc;
     for(i=1;i<=noc;i++)
     {
     	cin>>nosr>>nof;
     	for(j=0;j<nof;j++)
     	{
     		cin>>nos[j];
     	}
     	sort(nos,nos+nof,decreasing);
     	j=0;
     	while(nosr>0&&j<nof)
     	{
     		nosr=nosr-nos[j];
     		j++;

     	}
     	cout<<"Scenario #"<<i<<":\n";
     	if(nosr<=0)
     	{
          cout<<j<<"\n\n";
     	}
     	else
     	{
     		cout<<"impossible\n\n";
     	}	
     	
     }
 	return 0;
 }