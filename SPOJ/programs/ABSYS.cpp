# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
using namespace std;
int main()
 {
 	int noc;
 	int num1,num2,num3;
 	string t;
 	size_t found;
 	char str[1024],*token;
 	cin.getline(str,1024);
 	noc=atoi(str);
 	//cout<<noc<<"\n";
 	do
 	{
 		noc--;
 		cin.getline(str,1024);
 		cin.getline(str,1024);
 		//cout<<str<<" gdhrth\n";
        token=strtok(str," ");
        if(token!=NULL)
          t=string(token);
        //cout<<t<<" "<<token<<"\n";
        found=t.find("machula");
        if(found==string::npos)
        {
        	num1=atoi(token);
        	//cout<<"in if"<<num1<<"\n";
        }
        else
        {
        	num1=-1;
        }
        token=strtok(NULL," ");
        token=strtok(NULL," ");
        if(token!=NULL)
          t=string(token);
        found=t.find("machula");
        if(found==string::npos)
        {
        	num2=atoi(token);
        }
        else
        {
        	num2=-1;
        }
        token=strtok(NULL," ");
        token=strtok(NULL," ");
        if(token!=NULL)
          t=string(token);
        found=t.find("machula");
        if(found==string::npos)
        {
        	num3=atoi(token);
        }
        else
        {
        	num3=-1;
        }   
        if(num1==-1)
        {
        	num1=num3-num2;
        }
        else if(num2==-1)
        {
        	num2=num3-num1;
        }
        else if(num3==-1)
        {
        	num3=num1+num2;
        }
        cout<<num1<<" + "<<num2<<" = "<<num3<<"\n";
 	}while(noc>0);
 	return 0;
 }