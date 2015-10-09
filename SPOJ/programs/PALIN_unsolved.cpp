#include <iostream>
using namespace std;
string num;
int compare(int pos1,int pos2)
{
	bool eqflag=true;
   while(pos1>=0)
   {
  // 	cout<<num[pos1]<<" "<<num[pos2]<<"\n";
   	if(num[pos1]>num[pos2])
   	 {
   	 	eqflag=false;
   		pos1--;
   		pos2++;
   	 }
   	 else if(num[pos1]==num[pos2])
   	 {
   	 	pos1--;
   		pos2++;
   	 }
    else
    {
    	return -1;
    }
   }
  // cout<<"out of while\n";
   if(eqflag)
   return 0;
   else
   	 return 1;
}
int main()
{
	
	cin>>num;
	//cout<<num<<"\n";
	int len=num.length();
	int isgreater=-1;
	int part1,part2;
	if(len%2==1)
	{
		part1=len/2-1;
		part2=len/2+1;
	}
	else
	{
		part1=len/2-1;
		part2=len/2;
	}
//	cout<<part1<<" "<<part2<<"\n";
	isgreater=compare(part1,part2);
	while(isgreater==-1||isgreater==0)
	{
		/*isgreater=compare(part1,part2);
		if(isgreater==1)
	{
		/*for(int i=0;i<=part1;i++)
			cout<<num[i];
		if(len%2==1)
			cout<<num[len/2];
		for(int i=part1,j=part2;i>=0,j<len;i--,j++)
			num[j]=num[i];
	}
	else*/ if(isgreater==-1)
	{
		for(int i=part2;i<len;i++)
		{
			num[i]='0';
		}
	//	cout<<num<<"\n";
		if(len%2==1)
		{

            if((num[len/2]-48)<9)
            {
            	char t=num[len/2]++;
            	//cout<<t+1<<"redsfer\n";
            }
            else
            {
            //	cout<<num<<"\n";
            	num[len/2]='0';
            //	cout<<num<<" bsbh\n";
           // 	cout<<num.length()<<"dfe\n";
            	num[part1]++;
            } 
            for(int i=part1,j=part2;i>=0,j<len;i--,j++)
		            num[j]=num[i];
		}
		else
		{
//			cout<<"in else\n";
			for(int i=part1;i>=0;i--)
			{
				if((num[i]-48)<9)
				{
				//	cout<<"in if\n";
					num[i]++;
					break;
				}
				else
				{
					num[i]='0';
				}
//				cout<<num<<"\n";
			}

			for(int i=part1,j=part2;i>=0,j<len;i--,j++)
			{
				num[j]=num[i];
			}
		}
	//	cout<<num<<" fdgerg\n";
				//cout<<num<<"  dfr\n";
	}

	else
	{
	//	num[len-1]++;
		bool nflag=true;
		for(int i=len-1;i>=0;i--)
			{
				if((num[i]-48)<9)
				{
					nflag=false;
				//	cout<<"in if\n";
					num[i]++;
					break;
				}
				else
				{
					num[i]='0';
				}
		//		cout<<num<<"\n";
			}
		//num[0]=1;
			if(nflag)
			{
				string newnum="1";
				newnum.append(num);
				num=newnum;
				len=num.length();
				cout<<len<<"\n";
				if(len%2==1)
            	{
		          part1=len/2-1;
	              part2=len/2+1;
	            }
	           else
	            {
		           part1=len/2-1;
		           part2=len/2;
	             }
	             cout<<part1<<" "<<part2<<"\n";
			}
			
	}
//	cout<<num<<"rfd\n";
	isgreater=compare(part1,part2);
//	cout<<isgreater<<"\n";
	}
	if(isgreater==1)
	{
		/*for(int i=0;i<=part1;i++)
			cout<<num[i];
		if(len%2==1)
			cout<<num[len/2];*/
		for(int i=part1,j=part2;i>=0,j<len;i--,j++)
			num[j]=num[i];
	}
	cout<<num<<"\n";
	//cout<<"\n";
	//cout<<isgreater<<"\n";
	//cout<<compare(part1,part2)<<"\n";

	return 0;

}

