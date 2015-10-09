# include <iostream>
using namespace std;
int main()
 {
   int n;
   do
    {
      cin>>n;
      if(n!=0)
       {
          long int ans=n;
          ans=ans*(n+1);
          ans=ans*(2*n+1);
          ans=ans/6;
          cout<<ans<<'\n';

       }
    }
   while(n!=0);

   return 0;
 }
