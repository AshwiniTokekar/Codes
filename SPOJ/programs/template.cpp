#include<stdio.h>
# include<cstring>
#define MAX 1000000
long long int a[MAX]={0};
 
long long int max(long long int a,long long int b)
{
return a>b?a:b;
}
 
long long int split(long long int n)
{
long long int x1,x2,x3,x;
if(n==0)
return 0;
if(n<MAX)
{
if(a[n]==0){
x1=split(n/2);
x2=split(n/3);
x3=split(n/4);
x=x1+x2+x3;
a[n]=max(x,n);
}
return a[n];
}
else
{
x1=split(n/2);
x2=split(n/3);
x3=split(n/4);
x=x1+x2+x3;
return max(x,n);
}
}
 
int main()
{
long long int n,x;
while(scanf("%lld",&n)!=EOF)
{ memset(a,0,sizeof(a));
 
printf("%lld\n",split(n));
}
return 0;
}