#include <iostream>
#include <vector>
using namespace std;
void InsertionSort(vector<int>&A)
{
  int len=A.size();
  int i,j,v;
  bool swapped=true;
  for(i=2;i<=len-1;i++)
  {
    v=A[i];
    j=i;
    while(A[j-1]>v&&j>=1)
    {
      A[j]=A[j-1];
      j--;
    }
    A[j]=v;
  }
}
int main()
{
  vector<int>arr;
  arr.push_back(100);
  arr.push_back(108);
  arr.push_back(50);
  arr.push_back(90);
  arr.push_back(60);
  InsertionSort(arr);
  for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
  return 0;
}
