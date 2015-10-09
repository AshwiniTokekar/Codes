# include <iostream>
# include <cstring>
using namespace std;
int main()
 {
 	char n1[110],n2[110];
 	int x1[110],y1[110],x[110],y[110];
    int len1,len2;
    int i,j,k,l,temp;
 	for(i=0;i<10;i++)
 	{
 		cin>>n1;
 		cin>>n2;
        len1=strlen(n1);
        len2=strlen(n2);
        j=len2-1;
        k=len1-1;
        l=0;
        temp=0;
        //ADDITION
        while(j>=0)
        {
        	cout<<n1[k]<<" "<<n2[j]<<'\n';
        	temp+= (int)n1[k]+(int)n2[j]-96;
            x1[l]=temp%10;
            l++;
            temp/=10;      
        	//cout<<x[l-1]<<"\n";
        	j--;
        	k--;
        }
        while(k>=0)
        {
             temp+=(int)n1[k]-48;
             x1[l]=temp%10;
             temp/=10;
             l++;
             k--;
        }
        l--;
        while(l>=0)
        {
        	cout<<x1[l];
        	l--;
        }
       // cout<<x[2]<<x[1]<<x[0]<<"\n";
        cout<<"\n";
 	}
 	return 0;
 }