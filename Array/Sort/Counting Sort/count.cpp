#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sort(vector<int> &a,int n){
	int max=*max_element(a.begin(),a.end());
	int min=*min_element(a.begin(),a.end());
	vector<int> count(max-min+1), output(n);

	for(auto it: a){
		count[it-min]++;
	}
	for (int i = 1; i < count.size(); ++i)
	{
		count[i]+=count[i-1];
	}

	for (int i = n-1; i >= 0; i--)
	{
		output[--count[a[i]-min]]=a[i];
	}

	for (int i = 0; i <n; i++)
	{
		a[i]=output[i];
	}
}
int main()
{
	vector<int> a{2,1,2,1,1,2,2,1};
	int n=a.size();
	sort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}