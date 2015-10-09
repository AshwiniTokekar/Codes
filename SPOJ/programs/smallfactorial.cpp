#include <iostream>
using namespace std;
int main()
{

  int ans[200];
  int num,index,temp;
  int noc;
  cin>>noc;
  while(noc)
  {
    noc--;
    ans[0]=1;
    index=0;
    cin>>num;
    while(num>=2)
    {
        temp=0;
       for(int i=0;i<=index;i++)
         {
            temp+=(ans[i]*num);
            ans[i]=temp%10;
            temp=temp/10;
         }
       while(temp>0)
       {
         index++;
         ans[index]=temp%10;
         temp/=10;
       }
      num--;
     // for(int i=0;i<=index;i++)
      // cout<<ans[i];
      // cout<<"\n";
    }
    for(int i=index;i>=0;i--)
       cout<<ans[i];
    cout<<"\n";
  }

 return 0;
}
