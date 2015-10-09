# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
using namespace std;
string inp;
vector <char> str1(1000),str3(1000),str2(1000);
int main()
{
   int noc;
   int len;
   cin>>noc;
   while(noc)
   {
     noc--;
     cin>>inp;
     len=inp.size();
     if(len%2==0)
     {
       cout<<"gryiyfdygerf\n";
        reverse_copy(inp.begin(),(inp.begin()+(len/2)), str1.begin());
        copy(inp.begin()+(len/2),inp.end(),str3.begin());
     }
     else
     {
        cout<<"odd digits\n";
        reverse_copy(inp.begin(),(inp.begin()+(len/2)), str1.begin());
        copy((inp.begin()+(len/2)),inp.end(),str3.begin());
        copy((inp.begin()+(len/2)),(inp.begin()+(len/2)+1),str2.begin());
     }
     while(1)
     {
       if(len%2==0)
      {

        int i=0;
        while(str1[i]==str3[i])
              i++;

         if(str1[i]>str3[i])
          {
             int j=0;
             for(j=0;j<len/2;j++)
                cout<<inp[j];
             for(j=0;j<=len/2;j++)
              cout<<str1[j];
             cout<<"\n";
             break;
          }
      else
        {
           for(i=0;i<=len/2;i++)
               str3[i]='0';
        }
      }

     else if(len%2==1)
      {
         cout<<"odd digits\n";
         int j=0;
             for(j=0;j<len/2;j++)
                cout<<inp[j];
             cout<<str2[0];
             for(j=0;j<=len/2;j++)
              cout<<str1[j];
             cout<<"\n";
             break;
      }

     }

   }

  return 0;
}

