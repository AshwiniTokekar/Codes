#include <iostream>
#include <vector>
using namespace std;
void SelectionSort(vector<int>&A)
{
  int len=A.size();
  int i,j,min,temp;
  for(i=0;i<len-1;i++)
  {
    min=i;
    for(j=i+1;j<len;j++)
    {
      if(A[j]<A[min])
      {
        min=j;
      }
    }
    temp=A[min];
    A[min]=A[i];
    A[i]=temp;
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
  SelectionSort(arr);
  for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
  return 0;
}
