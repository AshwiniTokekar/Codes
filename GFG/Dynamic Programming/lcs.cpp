#include<iostream>
#include <vector>
using namespace std;
int lcs(string s1,string s2)
{
  int n1=s1.size();
  int n2=s2.size();
  cout<<s1<<" "<<s2<<"\n";
//  n1++;
//  n2++;
  vector<vector<int> >aux(n1+1,vector<int>(n2+1,0));
  for(int i=1;i<=n1;i++)
    for(int j=1;j<=n2;j++)
    {
//      cout<<s1[i-1]<<" "<<s2[j-1]<<"\n";
      if(s1[i-1]==s2[j-1])
      {
          aux[i][j]=aux[i-1][j-1]+1;
      }
      else if(aux[i][j-1]<=aux[i-1][j])
      {
           aux[i][j]=aux[i-1][j];
      }
      else
      {
        aux[i][j]=aux[i][j-1];
      }
    }
  return aux[n1][n2];
  
}
int main()
{
  cout<<lcs("ABCDGH","AEDFHR")<<"\n";
  return 0;
}
