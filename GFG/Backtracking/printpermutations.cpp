#include <iostream>
using namespace std;
void swap(char *x, char *y)
{
  char temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
void allpermutations(char* str,int l)
{
   int i;
   if(str[l]=='\0')
     cout<<str<<"\n";
   else
   {
     for(i=l;str[i]!='\0';i++)
     {
       swap((str+l),(str+i));
       allpermutations(str,l+1);
       swap((str+l),(str+i));
     }
   }
}
int main()
{
  char str[100];
  cin>>str;
  allpermutations(str,0);
  return 0;
}
