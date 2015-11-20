#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > adjmat(1000,vector<int>(1000));
vector<int>recieved(1000);
vector<int>send(1000);
int input(int n)
{
  int sum=0;
  int num;
  for(int i=0;i<1000;i++)
  {
    send[i]=recieved[i]=0;
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
     scanf("%d",&num);
     sum+=num;
     recieved[j]+=num;
     send[i]+=num;
    }
  return sum;
}
int reduction(int n)
{
  int ans=0;
  for(int i=0;i<n;i++)
    {
//       cout<<i<<" "<<send[i]<<" "<<recieved[i]<<"\n";
       ans+=(send[i]>recieved[i]?send[i]-recieved[i]:recieved[i]-send[i]);
    }
  ans=ans>>1;
  return ans;
}

int main()
{
  int k=0;
  int n;
  scanf("%d",&n);//n;
  while(n!=0)
  {
    k++;
    int B=input(n);
    int A=reduction(n);
//    printf("%d. %d %d\n",k,B,A);
    cout<<k<<". "<<B<<" "<<A<<"\n";
    scanf("%d",&n); //n;
  }
  return 0;
}
