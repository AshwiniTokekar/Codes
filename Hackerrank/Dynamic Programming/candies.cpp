#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>ranking(100001,0);
vector<int>noc(100001,1);

void calculatemin(int nos)
    {
       for(int i=1;i<nos;i++)
           {
              if(ranking[i-1]<ranking[i])
                  noc[i]=noc[i-1]+1;
              else if(ranking[i-1]==ranking[i]&&noc[i-1]>1)
                    noc[i]=noc[i-1]-1;
             else
                 {
                    int j=i;
                    while(j>=0&&ranking[j-1]>ranking[j])
                        {
                           noc[j-1]=noc[j-1]>noc[j]+1?noc[j-1]:noc[j]+1;
                           j--;
                    }
             }
       }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nos;
    cin>>nos;
    for(int i=0;i<nos;i++)
        cin>>ranking[i];
    calculatemin(nos);
    long long int sum=0;
    for(int i=0;i<nos;i++)
        {
          sum+=noc[i];
      //   cout<<noc[i]<<" ";
    }
  //  cout<<"\n";
    cout<<sum<<"\n";
    return 0;
}