#include <iostream>
#include <vector>
using namespace std;
int editdistance(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int> >dp(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;i++)
      for(int j=0;j<=n2;j++)
      {
        if(i==0)
          dp[i][j]=j;
        else if(j==0)
          dp[i][j]=i;
        else if(s1[i-1]==s2[j-1])
        {
          dp[i][j]=dp[i-1][j-1];
        }
        else
        {
          int min=dp[i][j-1];
          if(min>dp[i-1][j])
            min=dp[i-1][j];
          else if(min>dp[i-1][j-1])
            min=dp[i-1][j-1];
          min++;
          dp[i][j]=min;
        }
      }
    return dp[n1][n2];
}
int main()
{
  cout<<editdistance("abc","abc")<<"\n";
  cout<<editdistance("aaaa","aaba")<<"\n";
  return 0;
}
