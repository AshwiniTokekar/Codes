# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
int main()
{
    int num;
    float area;
    do
    {
       cin>>num;
       if(num==0)
       	 break;
       //r=(num/M_PI);
       area=(num*num);
       area=area/M_PI;
       area=area/2;
      // area=round(area)
       cout<<fixed<<setprecision(2)<<area<<"\n";
    }while(1);
	return 0;
}