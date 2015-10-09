# include <iostream>
# include <algorithm>
using namespace std;
int main()
 {
   int noc;
   int nom;
   int men[1010],women[1010];
   long int sop;
   cin>>noc;
   for(int i=0;i<noc;i++)
   {
     sop=0;
     cin>>nom;
     for(int j=0;j<nom;j++)
        cin>>men[j];
     for(int j=0;j<nom;j++)
         cin>>women[j];
     stable_sort(men,men+nom);
     stable_sort(women,women+nom);
     for(int j=0;j<nom;j++)
          {
            sop+=men[j]*women[j];
            //cout<<men[j]<<" "<<women[j]<<'\n';
          }

     cout<<sop<<'\n';

   }
   return 0;
 }
