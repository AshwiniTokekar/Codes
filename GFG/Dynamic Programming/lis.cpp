#include <iostream>
using namespace std;
//O(n2) solution
int lisN_2(int arr[],int n)
{
  int aux[n],max=0;
  for(int i=0;i<n;i++)
    aux[i]=1;
  for(int i=1;i<n;i++)
  {// cout<<arr[i]<<"=";
    for(int j=0;j<i;j++)
    {
      if(arr[i]>arr[j]&&aux[i]<aux[j]+1)
      {
     //   cout<<arr[j]<<" ";
        aux[i]=aux[j]+1;
      }
    }
    //cout<<"\n";
   }
  for(int i=0;i<n;i++)
  {
    //cout<<arr[i]<<"="<<aux[i]<<"\n";
    if(max<aux[i])
      max=aux[i];
  }
  return max;
}

int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  cout<<lisN_2(arr,8)<<"\n";
  return 0;
}
