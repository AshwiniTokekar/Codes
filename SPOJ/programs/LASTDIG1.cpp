# include <iostream>
using namespace std;
//int mat[10][5]={0,0,0,0,0,1,1,1,1,1,2,4,8,6,3,3,9,7,1,4,4,6,4,6,5,5,5,5,5,6,6,6,6,6,7,7,9,3,1,8,8,}
int main()
 {
 	int noc;
 	long long int x,y,x1;
 	cin>>noc;
 	for(int i=0;i<noc;i++)
 	{
 		cin>>x>>y;
 		if(y!=0)
 		{
 			y=y%4;
 			if(y==0)
 				y=4;
            x1=x; 
 	        for(int j=1;j<y;j++)
 			      x=x*x1;
 	    	cout<<x%10<<"\n";  
 		}
 		else if(y==0)
 		{
 			cout<<"1"<<"\n";
 		}
 		
 	} 
 	return 0;
 }