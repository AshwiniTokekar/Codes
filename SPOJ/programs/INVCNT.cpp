#include<stdio.h>
#include<stdlib.h>
long long int merge(long int *A,long int p,long int q, long int r) //p=min q=mid r=max
 {
  long long int inversions_count=0;
  long int i=p;
  long int j=q+1;
  long int k=0;
  long int aux[200000];  //auxillary array
  while(i<=q&&j<=r)
  {
    if(A[i]<=A[j])
      {
        aux[k]=A[i];
        i++;
      }  
    else
      {
        aux[k]=A[j];
        inversions_count+=(q+1-i);
        j++;
      }
    k++;   
  }
  while(i<=q)
    {
      aux[k]=A[i];
      k++;
      i++;
    }  
  while(j<=r)
      {
        aux[k]=A[j];
        k++;
        j++;
      }  
    for (i=p,k=0; i <=r; i++,k++)
       {
         A[i]=aux[k];  
       }  
    return inversions_count;   
  }
long long int mergesort(long int *A,long int p,long int r)
   {
    long int q = (p+r)/2;
    long long int inversions_count=0;
    if(p<r)
    {

      inversions_count+=mergesort(A,p,q);
      inversions_count+=mergesort(A,q+1,r);
      inversions_count+=merge(A,p,q,r);
    }
    return inversions_count;
   }
int main()
  {
    long int A[200000];
    int noc;
    long int now,i;
    long long int inversions;
    scanf("%d",&noc); 
    while(noc>0)
    {
      noc--;
      scanf("%ld",&now);
     for(i=0;i<now;i++)
     {
       scanf("%ld",&A[i]);
     }
      
    inversions=mergesort(A,0,now-1);
    printf("%lld\n",inversions);
    }
    return 0;
  }

  
 