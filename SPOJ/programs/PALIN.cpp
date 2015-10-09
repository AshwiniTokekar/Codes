#include <iostream>
#include <vector>
using namespace std;
vector<int> num(1000000);
int compare(int pos1,int pos2)
{
	bool eqflag=true;
   while(pos1>=0)
   {
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
   if(eqflag)
   return 0;
   else
   	 return 1;
}
int main()
{
	int noc;
	cin>>noc;
	while(noc)
	{
		noc--;
		string temp;
	cin>>temp;
	int len=temp.length();
	if(len==1)
	{
		cout<<"11\n";
	//	noc--;
		continue;

	}
	else
	{
		int i=0;
		while(i<len)
		{
			num[i]=temp[i]-'0';
			i++;
		}
	}
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
	isgreater=compare(part1,part2);
	if(isgreater==0)  // equal
	{
		bool nflag=true;
		for(int i=len-1;i>=0;i--)
			{
				if(num[i]<9)
				{
					nflag=false;
					num[i]++;
					break;
				}
				else
				{
					num[i]=0;
				}
			}
	//		cout<<num<<" "<<nflag<<"\n";
			if(nflag)
			{
				//string newnum="1";
				//newnum.append(num);
				//num=newnum;

				//len=len+1;
				len++;
				num[0]=1;
				//cout<<len<<"\n";
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
//	             cout<<part1<<" "<<part2<<"\n";
			}
	/*	for(int i=0;i<len;i++)
	       cout<<num[i];
	cout<<endl;*/
		isgreater=compare(part1,part2);	
	}
//	cout<<num<<"modified num\n";

	while(isgreater==-1)  //less than
	{
      
		for(int i=part2;i<len;i++)
		{
			num[i]=0;
		}
	//	cout<<num<<"\n";
		if(len%2==1)
		{

            if(num[len/2]<9)
            {
            	num[len/2]++;
            }
            else
            {
            	num[len/2]=0;
            	num[part1]++;
            } 
            for(int i=part1,j=part2;i>=0&&j<len;i--,j++)
		            num[j]=num[i];
		}
		else
		{
			for(int i=part1;i>=0;i--)
			{
				if(num[i]<9)
				{
					num[i]++;
					break;
				}
				else
				{
					num[i]=0;
				}
			}

			for(int i=part1,j=part2;i>=0&&j<len;i--,j++)
			{
				num[j]=num[i];
			}
		}
		
	isgreater=compare(part1,part2);
	//cout<<isgreater<<" isgreater\n";
	}
	if(isgreater==1)  //greater than
	{
		/*for(int i=0;i<=part1;i++)
			cout<<num[i];
		if(len%2==1)
			cout<<num[len/2];*/
		for(int i=part1,j=part2;i>=0&&j<len;i--,j++)
			num[j]=num[i];
	}
	for(int i=0;i<len;i++)
	    cout<<num[i];
	cout<<endl;
//	noc--;
	}
	return 0;

}

