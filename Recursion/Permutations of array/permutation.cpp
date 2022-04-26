#include <iostream>
#include <vector>
using namespace std;
void permutation(vector<int> v, int index, vector<vector<int>> &ans){
	if(index==v.size()){
		ans.push_back(v);
		return;
	}
	for(int i=index;i<v.size();i++){
		swap(v[index],v[i]);
		permutation(v,index+1,ans);
		swap(v[index],v[i]);
	}
}
int main()
{
	vector<int> v{1,3,4,8};
	vector<vector<int>> ans;
	int i=0;
	permutation(v,i,ans);
	for (int i = 0; i < ans.size(); ++i)
	{
		for(auto a:ans[i]){
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}