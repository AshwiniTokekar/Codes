# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
vector<int> m(1000000); //mechgodzilla
vector<int> g(1000000); //godzilla
bool mycomp (int i,int j) { return (i>j); }

int main()
{
    int noc;
    int ng,nm;
    cin>>noc;
    while(noc)
    {
    	noc--;
    	cin>>ng>>nm;
    	for(int i=0;i<ng;i++)
    		cin>>g[i];
    	for(int j=0;j<nm;j++)
    		cin>>m[j];
    	sort(g.begin(),g.begin()+ng,mycomp);
    	sort(m.begin(),m.begin()+nm,mycomp);
    	while(ng>0&&nm>0)
    	{
    		if(g[ng-1]>=m[nm-1])
    		{
                nm--;
    		}
            else
            {
            	ng--;
            }
    	}
    	if(ng==0)
    		cout<<"MechaGodzilla\n";
    	else
    		cout<<"Godzilla\n";

    }
	return 0;
}