#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
vector<int> CalcLongNumSum(string number1,string number2)
{
//   cout<<"In sum\n";
   vector<int>result;
   int carry=0;
   reverse(number1.begin(),number1.end());
   reverse(number2.begin(),number2.end());
   int len=number1.size()>number2.size()?number1.size():number2.size();
   int j=0;
   for(int i=0;i<len;i++)
   {
      int d1=(i<number1.size())?number1[i]-'0':0;
      int d2=(i<number2.size())?number2[i]-'0':0;
//      cout<<d1<<" "<<d2<<"\n";
      result.push_back(((d1+d2+carry)%10));
//      cout<<result<<"\n"; 
      j++;
      carry=(carry+d1+d2)/10;
   } 
   if(carry>0)
        result.push_back(carry);
   reverse(result.begin(),result.end());
   
   return result; 

}


int main()
{
   string num1,num2;
   cin>>num1>>num2;
   vector<int> ans=CalcLongNumSum(num1,num2);
   for(int i=0;i<ans.size();i++)
         cout<<ans[i];
   cout<<"\n"; 
  return 0;
}
