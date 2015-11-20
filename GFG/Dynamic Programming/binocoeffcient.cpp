#include<iostream>
#include <vector>
using namespace std;
long int binomialcoefficient(int n,int k)
{
//  int aux[n+1][n+1];
  vector<vector<long int> >aux(n+1,vector<long int>(n+1,0));
  for(int i=0;i<=n;i++)
  {
    aux[i][0]=1;
    aux[i][i]=1;
  }
  cout<<"i j\n";
  for(int i=1;i<=n;i++)
  {
   int min=i<k?i:k;
    for(int j=1;j<=min;j++)
    {
      aux[i][j]=aux[i-1][j-1]+aux[i-1][j];
//      cout<<i<<" "<<j<<" "<<aux[i][j]<<"\n";
      
    }
  }
  return aux[n][k];
}
int main()
{
  cout<<binomialcoefficient(10,6)<<"\n";
  return 0;
}
