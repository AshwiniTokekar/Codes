# include <iostream>
# include <algorithm>
using namespace std;
int pla[12],pld[12];
int main()
 {
 	int a,d;
 	do
 	{
      cin>>a>>d;
      if(a==0&&d==0)
      	 break;
      for(int i=0;i<a;i++)
        cin>>pla[i];
      for(int i=0;i<d;i++)
         cin>>pld[i];
      sort(pla,pla+a);
      sort(pld,pld+d);     	
      if(pla[0]<pld[0])
      	cout<<"Y\n";
      else if(pla[0]<pld[1])
      	cout<<"Y\n";
      else if(pla[0]>=pld[1])
      	cout<<"N\n";
 	}while(1);
 	return 0;
 }