#include<cstdio>
using namespace std;
int F[100000];  //Prefix table
char P[100000]; //Pattern
//Prefix Table Calculation for KMP Matcher
void initialize()
  {
     for(int i=0;i<10000;i++)
         F[i]=0;
  
  }
void PrefixTable(int m)
{
   int i=1,j=0;//,F[j]=0;
   while(i<m)
  {
     if(P[i]==P[j])
       {
          F[i]=j+1;
          i++;
          j++;
       }
     else if(j>0)
       {
         j=F[j-1];
       }
    else
      {
         F[i]=0;
         i++;
      } 
  
  }

}
//Actual KMP
int KMP(int n,int m)
{
   cout<<"KMP matcher\n";
   int i=0,j=0;
   bool flag=false;
   PrefixTable(m);
   initialize();
   while(i<n)
    {
       if(T[i]==P[j])
         {
            if(j==m-1)
              {
                flag=true;
                cout<<i-j<<"\n";
                i++;
                j=0;
              }
            else
              {
                i++;
                j++;
              }            
         }
      else if(j>0)
         {
            j=F[j-1];
         }
      else
          i++;
    }
   if(!flag)
    cout<<"\n";

}
int main()
{
     int n,m,j,i;
     char ch;
   while(scanf("%d",&m)!=EOF)
   {
     j=0;
     i=0;
     
     scanf("%s",P);
     PrefixTable();
     while(scanf("%c",ch)&&ch!='\n')
       {
           //i++;
            if(ch==P[j]&&j==m-1)
               {
                  ++i;
                  cout<<i-j-1;
                  j=0; 
               }
            else if(j>0)
               {
                 j=F[j-1];
                       
               }
            else
              {
                   i++;
             }
       }
    
       
   }
  return 0;
}
