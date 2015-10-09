#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int noc,num;
 // unsigned long long int =1;
  double pdt,nop,sqr;
  cin>>noc;
  while(noc)
   {
     noc--;
     nop=0;
     cin>>num;
     pdt=num;
   //  int temp=num; 
     if(num%2==0)
            {
//               cout<<"2\n";
               pdt*=0.5;
//               *=2;
    //           cout<<pdt<<"\n";
               nop++;
               while(num%2==0)
                {
                   num/=2;
                }
            }
//     cout<<num<<'\n';
     int i=3;
     sqr=sqrt(num);
//     cout<<"sqrt="<<sqr<<"\n";
     while(i<=sqr&&num>1)
      {
         if(num%i==0)
            {
  //             cout<<i<<"\n";
               pdt*=((float)(i-1)/(float)i);
 //              *=i;
    //           cout<<pdt<<"\n";
               nop++;
               while(num%i==0)
                {
                   num/=i;
                }
            }
         i+=2;
      }
      if(num==1)
          cout<<pdt<<"\n";
      else
        {
            
           pdt*=((float)(num-1)/(float)num);    
    //      cout<<"Before mult "<<pdt<<"\n";
        //  pdt/=;
      
          cout<<pdt<<"\n";
        }
   }
  return 0;
}
