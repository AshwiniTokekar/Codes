# include <iostream>
using namespace std;
long long int preprocess[1000001];
void initialize()
{
	for (long int i=0;i<=100000;i++)
	{
		if(i<=11)
			preprocess[i]=i;
		else
			preprocess[i]=0;
	}
}
long long int calc(long long int i)
{
	 if(preprocess[i]==0)
     {
     	long long int sum=calc(i/2)+calc(i/3)+calc(i/4);
     	preprocess[i]=sum>i?sum:i;
     }     
    return preprocess[i];
}
long long int calc1(long long int num)
{
    
        long long int num4,num3,num2,ans2,ans3,ans4;
    	long long int sum=0;
    	num2=num/2;
    	num3=num/3;
    	num4=num/4;
    	if(num2<=1000000)
    	{
    		sum=preprocess[num/2]+preprocess[num/3]+preprocess[num/4];
    	}
    	else if(num3<=1000000)
    	{
    		ans2=calc1(num2);
    		sum=ans2+preprocess[num/3]+preprocess[num/4];
    	}
    	else if(num4<=1000000)
         {
         	ans2=calc1(num2);
         	ans3=calc1(num3);
            sum=ans2+ans3+preprocess[num/4];
         }
         else
         {
         	ans2=calc1(num2);
         	ans3=calc1(num3);
            ans4=calc1(num4);
            sum=ans2+ans3+ans4;
         }
    return sum>num?sum:num;;
}
int main()
{
	long long int num;
	initialize();
   for (long int i=12;i<=1000000;i++)
	{
			calc(i);
	}
   while(cin>>num)
   {
   	 if(num<=1000000)
   	 	cout<<preprocess[num]<<"\n";
   	 else
   	 	cout<<calc1(num)<<"\n";
   }
	return 0;
}