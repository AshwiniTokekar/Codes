#include<stdio.h>
long long even(long long int n)
    {
        // for even levels
    	return ((n*(n+2)*(2*n+1))/8);
    }
long long odd(long long int n)
    {
        // for odd levels
    	return ((n*(n+2)*(2*n+1)-1)/8);
    }
void main()
{
	long long int lev; // level of triangle
	while(1)
	{
		scanf("%lld", &lev);
		if(lev==-1)
			break;
		if(lev%2==0)
			printf("%lld\n",even(lev));
		else
			printf("%lld\n",odd(lev));
	}
}
