#include <iostream>
using namespace std;
int main()
{
  long int noc;
  long long int num,ans;
  cin>>noc;
  while(noc)
  {
    noc--;
    cin>>num;
    ans=0;
    while(num>0)
    {
      ans+=num/5;
      num/=5;

    }
    cout<<ans<<"\n";
  }
 return 0;
}
