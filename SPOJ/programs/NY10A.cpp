# include <iostream>
using namespace std;
//enum Heads{TTT, TTH, THT, THH, HTT, HTH, HHT,HHH};
int A[8];
void initialize()
{
	for(int i=0;i<8;i++)
		A[i]=0;
}
int main()
{
	int seqno,noc,len;
	string seq;
	cin>>noc;
	while(noc)
	{
		noc--;
		initialize();
		int sum;
		cin>>seqno;
        cin>>seq;
        len=seq.length();
        len-=2;
        for(int i=0;i<len;i++)
        {
             sum=0;
      //       cout<<seq[i]<<seq[i+1]<<seq[i+2]<<" ";
             if(seq[i]=='H')
             	sum=1*2;
             else
                sum=1*5; 
            if(seq[i+1]=='H')
             	sum+=2*2;
             else
                sum+=2*5; 
            if(seq[i+2]=='H')
             	sum+=3*2;
             else
                sum+=3*5; 
        //    cout<<sum<<"\n";
            switch(sum)
            {
            	case 30:A[0]++;
            	      break;
            	case 21:if(seq[i]=='T')
            	           A[1]++;
            	         else
            	           A[6]++;  
            	      break;
            	case 24:A[2]++;
            	      break;
            	case 15: A[3]++;
            	       break;
            	case 27: A[4]++;
            	       break;
            	case 18:A[5]++;
            	      break;
            	case 12: A[7]++;
            	       break;                                                

            }
        }
        cout<<seqno<<" ";
        for(int i=0;i<8;i++)
        	 cout<<A[i]<<" ";
        cout<<"\n";	

	}
	return 0;
}