#include<iostream>
#include<string>
using namespace std;
int main()
{
   string num1;
   int num2,rem,noc,newnum;
   cin>>noc;
   while(noc)
   {
     noc--;
     newnum=0;
     cin>>num2>>num1;
     int i=0;
     if(num2==0)
        {
           //cout<<num1<<"\n";
           int i=0;
           while(num1[i]!='\0')
          {
            cout<<int(num1[i]-'0');
        
              i++;           
          }
           cout<<"\n";
          continue;
        }
     else if(num1.compare("0")==0)
       {
         cout<<num2<<"\n";
         continue;
       }
     while(num1[i]!='\0')
      {
          newnum=(num1[i]-'0')+newnum*10;
          newnum%=num2;
          i++;           
      }
//     cout<<newnum<<"\n";
     if(newnum==0)
        {
          cout<<num2<<"\n";
          continue;
        }
     while(num2%newnum!=0)
      {
           rem=num2%newnum;
           num2=newnum;
           newnum=rem;
      } 
     cout<<newnum<<"\n";

   }

   return 0;
}
