# include <iostream>
using namespace std;
int main()
{
	int noc;
	long long int level;
	long long int sum,part1,part2;
	cin>>noc;
	while(noc)
	{
		noc--;
        cin>>level;
        //cout<<level*(level+1)<<"\n";
        part1=(level*(level+1))%1000007;
        part2=((level*(level-1))/2)%1000007;
       // part2=part2/2;
     //   cout<<part1<<" "<<part2<<"\n";
        sum=(part1+part2)%1000007;
        cout<<sum<<"\n"; 

	}
	return 0;
}