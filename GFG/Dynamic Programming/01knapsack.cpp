#include <iostream>
#include <vector>
using namespace std;
int knapsack(vector<int>wt,vector<int>val,int W)
{
  int len=wt.size();
  vector<vector<int> >aux(len+1,vector<int>(W+1,0));
  for(int i=0;i<=len;i++)
    for(int j=0;j<=W;j++)
    {
      if(i==0||j==0)
      {
        aux[i][j]=0;
      }
      else if(j>=wt[i-1])
      {
        aux[i][j]=(aux[i-1][j-wt[i-1]]+val[i-1]>aux[i-1][j])?(aux[i-1][j-wt[i-1]]+val[i-1]):aux[i-1][j];
      }
      else
        aux[i][j]=aux[i-1][j];
    }
  return aux[len][W];
}

int main()
{
  vector<int>wt(3);
  wt.push_back(10);
  wt.push_back(20);
  wt.push_back(30);

  vector<int>val(3);
  val.push_back(160);
  val.push_back(100);
  val.push_back(120);//={60,100,120};
  cout<<knapsack(wt,val,50)<<"\n";
  return 0;
}
