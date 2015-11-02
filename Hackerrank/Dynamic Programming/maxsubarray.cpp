#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long int maxcontiguous(vector<int> arr)
      {
             int len=arr.size();
             if(len==1)
                 return arr[0];
             long long int f=0;
             long long  int e_h=0;
             for(int i=0;i<len;i++)
                 {
                              e_h+=arr[i];
                              if(e_h<0&&i!=0)
                                  e_h=0;
                              else if(f<e_h&&i!=0)
                                  f=e_h;
                              else if(i==0)
                                  {
                                                   f=e_h;
                                                   if(e_h<0)
                                                       e_h=0;
                                               }
                                  
                        }
          return f;
      }
long long int maxnoncontiguous(vector<int>arr)
      {
            int len=arr.size();
            if(len==1)
                return arr[0];
            long long  int sum=0;
            int max=arr[0];
            long long int inc=arr[0],notinc=0;
            for(int i=1;i<len;i++)
                {
                             sum=(inc>notinc)?inc:notinc;
                             inc=sum+arr[i];
                             notinc=sum;
                             if(max<arr[i])
                                 max=arr[i];
                      }
          sum=((inc>notinc)?inc:notinc);
          if(sum==0)
              return max;
          else
              return sum;
      }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int noc,n;
    cin>>noc;
    while(noc)
        {
                  noc--;
                 
                  cin>>n;
                   vector<int> arr(n,0);
                  for(int i=0;i<n;i++)
                      cin>>arr[i];
                  cout<<maxcontiguous(arr)<<" "<<maxnoncontiguous(arr)<<"\n";
            }
    return 0;
}

