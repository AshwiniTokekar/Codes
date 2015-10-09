# include <iostream>
using namespace std;
int main()
{
  int arr[10000];
  int nop,i;
  long int sum,ans,quo;
  cin>>nop;
  while(nop!=-1)
   {
     sum=0;
     ans=0;
     for(i=0;i<nop;i++)
       {
         cin>>arr[i];
         sum+=arr[i];
       }
     if(sum%nop!=0)
       cout<<"-1\n";
     else
       {
         quo=sum/nop;
          for(i=0;i<nop;i++)
          {
             if(arr[i]>quo)
               ans+=arr[i]-quo;
          }
         cout<<ans<<'\n';
       }
       cin>>nop;

  }
  return 0;
}
