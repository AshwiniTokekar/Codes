#include <iostream>
#include <vector>
using namespace std;
void BubbleSortImproved(vector<int>&A)
{
  int len=A.size();
  int pass,i,temp;
  bool swapped=true;
  for(pass=len-1;pass>=0&&swapped;pass--)
  {
      swapped=false;
       for(i=0;i<=pass-1;i++)
       {
         if(A[i]>A[i+1])
         {
           temp=A[i];
           A[i]=A[i+1];
           A[i+1]=temp;
           swapped=true;
         }
       }
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
  BubbleSortImproved(arr);
  for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
  return 0;
}
