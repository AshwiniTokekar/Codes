#include <iostream>
#include <cmath>
using namespace std;
bool checkprime(int num)
{
    int temp=num;
    while(num%2==0)
       num/=2;
    int i=3;
    int sqr=sqrt(num);
    while(i<=sqr)
     {
          if(num%i==0)
             num/=2;
       i+=2;

     }
    return (temp==num);
}
int main()
{

   cout<<"2,";
   for(int i=3;i<=1000;i++)
    {

      if(checkprime(i))
           cout<<i<<",";

    }
   cout<<"\n";
  return 0;
}
