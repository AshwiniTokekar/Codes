#include<iostream>
#include<map>
using namespace std;
int main()
{
  int nop,result=0,temp;
//  map <int,int>pyanis(500000);
  cin>>nop;
  for(int i=0;i<nop;i++)
   {
       cin>>temp;
      result^=temp;   

   }
   cout<<result<<"\n";






  return 0;
}
