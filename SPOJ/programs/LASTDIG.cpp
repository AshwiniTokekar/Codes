# include <iostream>
using namespace std;
int main()
 {
 	int noc;
 	long long int x,y,x1;
 	cin>>noc;
 	for(int i=0;i<noc;i++)
 	{
 		cin>>x>>y;
 		/*if(x%2==0&&y%4==0&&y!=0)
 		  {
 		  	cout<<"6\n";
 		  }
 		else if(x%2==1&&y%4==0&&y!=0)
 		  {
 		  	cout<<"1\n";
 		  }  
 		else
 		{*/
            y=y%4;
            x1=x; 
 			for(int j=1;j<y;j++)
 				{
 					x=x*x1;
 			    }
 			cout<<x%10<<"\n";
 			
 		//}  
 	} 
 	return 0;
 }