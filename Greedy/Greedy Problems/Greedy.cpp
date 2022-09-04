#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Jobs
{
	int id;
	int deadline;
	int profit;
};

void JobScheduling(Jobs *Job, int n)
{
	sort(Job,Job+n,[](Jobs a, Jobs b){return a.profit>b.profit;});
	int maxDeadline=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		maxDeadline=max(maxDeadline+1,Job[i].deadline);
	}
	vector<int> v(maxDeadline,-1);
	int count=0,maxProfit=0;
	for (int i = 0; i < n; ++i)
	{
		int currProfit=Job[i].profit;
		int currJobId=Job[i].id;
		int currDead=Job[i].deadline;
		for(int k=currDead;k>0;k--){
			if(v[k]==-1){
				v[k]=currJobId;
				count++;
				maxProfit+=currProfit;
				break;
			}
		}
	}
	cout<<count<<" "<<maxProfit<<endl;
}

int main()
{
	Jobs Job[]={{1,2,50},{2,2,10},{3,2,40},{4,3,70}};
	int n=sizeof(Job)/sizeof(Job[0]);
	
	// assuming starting time of all jobs = 0 sec.

	cout<<"id"<<" "<<"deadline"<<" "<<"profit"<<endl;
	for(int i=0;i<n;i++){
		cout<<Job[i].id<<"      "<<Job[i].deadline<<"      "<<Job[i].profit<<endl;
	}
	JobScheduling(Job, n);
	
	
	return 0;
}
