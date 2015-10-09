# include <iostream>
using namespace std;
long int A[100001],B[100001];
int main ()
 {
 	long int size;
 	int flag=0;
 	do
 	{
 		flag=0;
        cin>>size;
        if(size==0)
        	break;
        for(int i=1;i<=size;i++)
        {
        	cin>>A[i];
        	B[A[i]]=i;
        	if(B[i]!=A[i])
                flag=1;
        }
       /* for(int i=1;i<=size;i++)
        {
            if(A[i]!=B[i])
            {
            	flag=1;
            	break;
            }
        }*/
        if(flag==0)
        	cout<<"ambiguous\n";
        else
        	cout<<"not ambiguous\n";
 	}while(size!=0);
 	return 0;
 }