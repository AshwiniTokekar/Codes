#include <iostream>
#include <vector>
using namespace std;
int lps(string str)
{
  int len=str.length();
  vector<vector<int> >aux(len+1,vector<int>(len+1,0));
//  vector<vector<int> >count(len+1,vector<int>(len+1,0));
  for(int i=0;i<len;i++)
    aux[i][i]=1;
  for(int cl=2;cl<=len;cl++)
    for(int i=0;i<len-cl+1;i++)
    {
      int j=i+cl-1;
      if(str[i]==str[j]&&cl==2)
      {
         aux[i][j]=2;
//         count[i][j]=
      }
      else if(str[i]==str[j])
        aux[i][j]=aux[i+1][j-1]+2;
      else
        aux[i][j]=aux[i+1][j]>aux[i][j-1]?aux[i+1][j]:aux[i][j-1];
    }
  for(int i=0;i<len;i++)
  {
    for(int j=0;j<len;j++)
    {
      cout<<aux[i][j]<<" ";
    }
    cout<<"\n";
  }
  return aux[0][len-1];
}
int main()
{
  cout<<"The largest Palindromic subsequence in BBABCBCAB "<<lps("ABCB")<<"\n";
  return 0;
}
