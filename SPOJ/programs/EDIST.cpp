#include <iostream>
#include <cstring>
using namespace std;
int Table[2][2010];
char A[2010],B[2010];
void initialize()
  {
     for(int i=0;i<=100;i++)
      for(int j=0;j<=100;j++)
      {
           if(i==0&&j==0)
            Table[i][j]=0;
           else if(i==0)
           {
              Table[i][j]=j;
           }
           else if(j==0)
           {
             Table[i][j]=i;
           }
           else
            Table[i][j]=0;
      }
  }
int editdistance()
   {
      int len1=strlen(A);
      int len2=strlen(B);
      for(int i=0;i<=len1;i++)
      {

        for(int j=0;j<=len2;j++)
        {
     //     cout<<Table[i][j]<<" ";
          if(A[i]==B[j])
            Table[i+1][j+1]=Table[i][j];
          else if(A[i]!=B[j])
          {
            int min=Table[i][j]+1;  // replace
            if(min>Table[i-1][j]+1)  // insert
              min=Table[i][j+1]+1;
            if(min>Table[i+1][j]+1) // del
              min=Table[i+1][j]+1;
            Table[i+1][j+1]=min;
          }
        }
      //  cout<<"\n";
       }  
        return Table[len1][len2];
   }
int main()
{
  initialize();
 // char B[]="MONEY";
  cin>>A>>B;
  cout<<editdistance()<<"\n";
  return 0;
}