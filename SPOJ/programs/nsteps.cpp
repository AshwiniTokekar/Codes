# include <iostream>
using namespace std;
int main()
  {
     long int noc,x,y;
     cin>>noc;
     while(noc)
      {
        noc--;
        cin>>x>>y;
         if(x==y&&x%2==0)
             cout<<x+y<<"\n";
         else if(x==y&&x%2==1)
             cout<<x+y-1<<"\n";
         else if(x==y+2&&x%2==0)
             cout<<x+y<<"\n";
         else if(x==y+2&&x%2==1)
             cout<<x+y-1<<"\n";
         else
           cout<<"No Number\n";

      }
    return 0;
  }

