#include <iostream>
#include <vector>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>&arr,int l,int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 
    for (int j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
void QuickSort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, h);
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
  QuickSort(arr,0,4);
  for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
  return 0;
}
