#include <iostream>
#include <vector>
using namespace std;
const int R=3,C=3;
int min(int x,int y,int z)
{
  int m;
  m=(x<y)?x:y;
  m=(m<z)?m:z;
  return m;
}
int mincost(int cost[R][C],int m,int n)
{
  vector<vector<int> >dp(R+1,vector<int>(C+1,0));
  dp[0][0]=cost[0][0];
  for(int i=1;i<=R;i++)
  {
    dp[i][0]=dp[i-1][0]+cost[i][0];
  }

  for(int i=1;i<=C;i++)
  {
    dp[0][i]=dp[0][i-1]+cost[0][i];
  }

  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {
      dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+cost[i][j];
    }
  return dp[m][n];
}
int main()
{
  int cost[R][C] = { {1, 2, 3},
                        {4, 8, 2},
                        {1, 5, 3} };
  cout<<mincost(cost,2,2)<<"\n";
  return 0;
}
