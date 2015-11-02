#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int maxways(vector<int> coins,int noc,int sum)
      {
        //    int len=coins.size();
            vector< vector<long long int> >dp(sum+1,vector<long long int>(noc,0));
            for(int i=0;i<noc;i++)
                dp[0][i]=1;
            for(int i=1;i<sum+1;i++)
                {
                         //   cout<<dp[i].size()<<"=";
                            for(int j=0;j<noc;j++)
                                {
                                                  //Including the coin coins[j]
                                                  long long int x=((i-coins[j])>=0)?dp[(i-coins[j])][j]:0;
                                                  //Exclunding the coin coins[j]
                                                 long long  int y=(j>=1)?dp[i][j-1]:0;
                                                  dp[i][j]=x+y;
                                           //       cout<<dp[i][j]<<" ";
                                            }
                          //cout<<"\n";
                      }
          return dp[sum][noc-1];
      }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int c,n;
    cin>>n>>c;
    vector<int>coins(c);
    for(int i=0;i<c;i++)
        cin>>coins[i];
   // sort(coins.begin(),coins.end());
    cout<<maxways(coins,c,n)<<"\n";
    return 0;
}
