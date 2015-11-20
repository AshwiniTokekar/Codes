#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int getmin(vector<int>p)
{
  int len=p.size();
  vector<vector<int> >aux(len+1,vector<int>(len+1,0));
  for(int L=2;L<len;L++)
  {
    for(int i=1;i<=len-L+1;i++)
    {
      int j=i+L-1;
      aux[i][j]=INT_MAX;
      for(int k=i;k<j;k++)
      {
        int q=aux[i][k]+aux[k+1][j]+p[i-1]*p[k]*p[j];
        if(q<aux[i][j])
          aux[i][j]=q;
      }
    }
  }
  return aux[1][len-1];
}
int main()
{
  vector<int>matorder(4,0);
  for (int i=0;i<4;i++)
    matorder[i]=(i+1);
  for(int i=0;i<4;i++)
    cout<<matorder[i]<<" ";
  cout<<"\n";
  cout<<"Minimum number of multiplications is "<<getmin(matorder)<<"\n";
  return 0;
}
