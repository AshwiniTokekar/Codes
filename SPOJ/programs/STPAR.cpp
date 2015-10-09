# include <iostream>
# include <stack>
using namespace std;
int arr[1000];
int main()
{
    int lno,cur,i;
    stack <int> arran;
    do
     {
     	//cout<<"inrdrdf\n";
     	cin>>lno;
     	//cout<<"fdewsd\n";
     	if(lno==0)
     		break;
     	for(i=0;i<lno;i++)
     		cin>>arr[i];
     	//cout<<"efsiudkiwe\n";
        i=0;
        cur=1;
        while(i<lno)
        {
        	if(arr[i]==cur)
        	{
        		cur++;
        		i++;
        	}

            else if(!arran.empty()&&arran.top()==cur)
               {
               	  arran.pop();
               	  cur++;
               }  
            else
            {
            	arran.push(arr[i]);
            	i++;
            }   

        }
        while(cur<=lno)
        {
        	if(!arran.empty()&&arran.top()==cur)
               {
               	  arran.pop();
               	  cur++;
               }  
            else 
            {
                break;
            }   
        }
        if(arran.empty())
        	cout<<"yes\n";
        else
        	cout<<"no\n";
        while(!arran.empty())
        	arran.pop();
       // arran.clear();
     } while (1); 
	return 0;
}