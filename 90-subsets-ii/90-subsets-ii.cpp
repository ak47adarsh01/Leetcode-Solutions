class Solution {
    
     // Solution using Backtarcking 
    
private:
     void solve(vector<int>&nums,vector<int>&ans,vector<vector<int>>&output,int index){
        output.push_back(ans);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){
                continue;
            }
            ans.push_back(nums[i]);
            solve(nums,ans,output,i+1);
            ans.pop_back();
        }
    }
public:    
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>output;
        sort(nums.begin(),nums.end());
        solve(nums,ans,output,0);
        return output;
    }
};