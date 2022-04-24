class Solution {
    vector<vector<int>> a;
    void solve(vector<int> &sub, vector<int> &nums, int i){
        if(i==nums.size()){
            a.push_back(sub);
            return;
        }
        solve(sub,nums,i+1);
        sub.push_back(nums[i]);
        solve(sub,nums,i+1);
        sub.pop_back();
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        solve(sub,nums,0);
        vector<vector<int>> ans;
        for (int i=0;i<a.size();i++){
            if(count(a.begin(), a.end(), a[i])==1)
            {
                ans.push_back(a[i]);
            }
            else{
                if(count(ans.begin(), ans.end(), a[i])==0)
                {
                    ans.push_back(a[i]);
                }
            }
        }
        return ans;
    }
};