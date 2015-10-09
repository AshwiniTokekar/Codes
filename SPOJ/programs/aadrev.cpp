#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
  int noc;
  int num1,num2,r1,r2;
  long int ans,ansr;
  cin>>noc;
  while(noc)
  {
     noc--;
     r1=0;
     r2=0;
     cin>>num1>>num2;
     while(num1>0)
      {
        r1=r1*10+num1%10;
        num1=num1/10;
      }
     while(num2>0)
      {
        r2=r2*10+num2%10;
        num2=num2/10;
      }
      ans=r1+r2;
      ansr=0;
      while(ans>0)
      {
        ansr=ansr*10+ans%10;
        ans=ans/10;
      }
      cout<<ansr<<"\n";
   }
 return 0;
}
