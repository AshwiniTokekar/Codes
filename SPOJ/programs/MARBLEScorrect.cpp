#include<stdio.h>
#include<math.h>
long long int C(long long int n,long long int r) {
  long long int i,j=1,k=1,res = 1;
  if(r> n/2)
    r = n-r;
 
  for(i = 0;i<r;i++) {
//    printf("J %lld \n",j);
    
 
    res *=  n--;
    res /= i+1;
    
  }
  //printf("%lld %lld\n",j,k);
  return res; 
}
 
    
int main(int argc,char** argv) {
  int T; 
  long long int N, K,R,n,r;
  
  scanf("%d",&T);
  while(T--) {
    scanf("%lld %lld",&N,&K);
    r= N - K;        // already choosen the K marbles one from each type
    n = K + r - 1;
//    printf("%lld %lld \n",n,r);
    printf("%lld\n", C(n,r));
  }
  return 0;
}