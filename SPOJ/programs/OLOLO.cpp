#include<cstdio>
using namespace std;
int main()
{
  int nop;
   long long int result=0,temp;
  scanf("%d",&nop);
  for(int i=0;i<nop;i++)
   {
       scanf("%lld",&temp);
      result=result^temp;   

   }
   printf("%lld\n",result);






  return 0;
}
