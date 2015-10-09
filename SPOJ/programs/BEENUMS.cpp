# include <iostream>
# include <cmath>
using namespace std;
int main()
 {
 	long long int num,x;
 	do
 	{
 		x=1;
       cin>>num;
       if(num==-1)
       	break;
      num--;
      while(num>0)
      {
      	num-=x*6;
      	x++;
      }
       if(num==0)
         {
             cout<<"Y\n";
         }
       else
        {
            cout<<"N\n";
        }  


 	}while(1);
 	return 0;
 }